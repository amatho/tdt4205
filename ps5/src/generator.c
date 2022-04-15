#include "tlhash.h"
#include <vslc.h>

/**Generate table of strings in a rodata section. */
void generate_stringtable(void);
/**Declare global variables in a bss section */
void generate_global_variables(void);
/**Generate function entry code
 * @param function symbol table entry of function */
void generate_function(symbol_t *function);
/**Generate code for a node in the AST, to be called recursively from
 * generate_function
 * @param node root node of current code block */
static void generate_node(symbol_t *func, node_t *node);
/**Initializes program (already implemented) */
void generate_main(symbol_t *first);

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define MOVQ(S, D) "\tmovq " S ", " D
#define PUSHQ(S) "\tpushq " S
#define POPQ(D) "\tpopq " D
#define ADDQ(S, D) "\taddq " S ", " D
#define SUBQ(S, D) "\tsubq " S ", " D
#define CALL(OP) "\tcall " OP
#define LEAVE "\tleave"
#define RET "\tret"

#define ICE(MSG)                                                               \
    fprintf(stderr, "internal compiler error: " MSG "\n");                     \
    exit(EXIT_FAILURE)

static const char *record[6] = {"%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9"};

void generate_program(void) {
    /* TODO: Emit assembly instructions for functions, function calls,
     * print statements and expressions.
     * The provided function 'generate_main' creates a program entry point
     * for the function symbol it is given as argument.
     */

    // TODO: Implement
    // - Generate string table
    // - Declare global variables
    // - Generate code for all functions
    // - Generate main (function already implemented) by assigning either the
    //   function named main or the first function of the source file if no
    //   main exists.
    generate_stringtable();
    generate_global_variables();

    size_t num_globals = tlhash_size(global_names);
    symbol_t *globals[num_globals];
    tlhash_values(global_names, (void **)globals);
    for (size_t i = 0; i < num_globals; i++) {
        if (globals[i]->type == SYM_FUNCTION) {
            generate_function(globals[i]);
        }
    }

    symbol_t *main_func = NULL;
    tlhash_lookup(global_names, "main", strlen("main"), (void **)&main_func);

    if (main_func == NULL) {
        if (num_globals > 0) {
            for (size_t i = 0; i < num_globals; i++) {
                if (globals[i]->type == SYM_FUNCTION) {
                    generate_main(globals[i]);
                    break;
                }
            }
        }
    } else {
        generate_main(main_func);
    }
}

void generate_stringtable(void) {
    /* These can be used to emit numbers, strings and a run-time
     * error msg. from main
     */
    puts(".section .data");
    puts(".intout:\t.asciz \"\%ld \"");
    puts(".strout:\t.asciz \"\%s \"");
    puts(".errout:\t.asciz \"Wrong number of arguments\"");

    for (size_t i = 0; i < stringc; i++) {
        char *str = string_list[i];
        printf(".STR%zu:\t.asciz %s\n", i, str);
    }

    putchar('\n');
}

void generate_global_variables(void) {
    puts(".section .bss");
    puts(".align 8");

    size_t num_globals = tlhash_size(global_names);
    symbol_t *globals[num_globals];
    tlhash_values(global_names, (void **)globals);
    for (size_t i = 0; i < num_globals; i++) {
        if (globals[i]->type == SYM_GLOBAL_VAR) {
            printf(".%s:\n", globals[i]->name);
        }
    }

    putchar('\n');
}

void generate_function(symbol_t *function) {
    puts(".section .text");
    printf(".global _%s\n", function->name);
    printf("_%s:\n", function->name);
    puts("\t// Function prologue");
    puts(PUSHQ("%rbp"));
    puts(MOVQ("%rsp", "%rbp"));

    for (size_t i = 0; i < MIN(function->nparms, 6); i++) {
        printf(PUSHQ("%s") "\n", record[i]);
    }

    size_t num_local_vars = tlhash_size(function->locals) - function->nparms;
    if (num_local_vars > 0) {
        printf(SUBQ("$%zu", "%%rsp") "\n", num_local_vars * 8);
    }

    if ((tlhash_size(function->locals) & 1) == 1) {
        puts(SUBQ("$8", "%rsp") "\t // align stack");
    }

    puts("\n\t// Function body");

    generate_node(function, function->node);

    puts("\n\t// Function epilogue");

    puts(MOVQ("%rbp", "%rsp"));
    puts(MOVQ("$0", "%rax"));
    puts(POPQ("%rbp"));
    puts(RET);

    putchar('\n');
}

static void gen_ident(symbol_t *func, node_t *node) {
    symbol_t *sym = node->entry;
    int64_t arg_offset = 0;
    switch (sym->type) {
    case SYM_GLOBAL_VAR:
        printf("._%s", sym->name);
        break;
    case SYM_PARAMETER:
        if (sym->seq >= 6) {
            printf("%ld(%%rbp)", 8 * (sym->seq - 4));
        } else {
            printf("%ld(%%rbp)", -8 * (sym->seq + 1));
        }
        break;
    case SYM_LOCAL_VAR:
        arg_offset = -8 * MIN(func->nparms, 6);
        printf("%ld(%%rbp)", -8 * (sym->seq + 1) + arg_offset);
        break;
    default:
        ICE("invalid identifier");
        break;
    }
}

static void gen_func_call(node_t *node) {}

static void gen_expr(symbol_t *func, node_t *node) {
    if (node->type == IDENTIFIER_DATA) {
        printf("\tmovq ");
        gen_ident(func, node);
        puts(", %rax");
    } else if (node->type == NUMBER_DATA) {
        printf(MOVQ("$%ld", "%%rax") "\n", *(int64_t *)node->data);
    } else if (node->n_children == 1) {
        switch (*(char *)node->data) {
        case '-':
            gen_expr(func, node->children[0]);
            puts("\tnegq %rax");
            break;
        case '~':
            gen_expr(func, node->children[0]);
            puts("\tnotq %rax");
            break;
        default:
            ICE("invalid expression");
            break;
        }
    } else if (node->n_children == 2) {
        if (node->data != NULL) {
            switch (*(char *)node->data) {
            case '+':
                gen_expr(func, node->children[0]);
                puts(PUSHQ("%rax"));
                gen_expr(func, node->children[1]);
                puts(ADDQ("%rax", "(%rsp)"));
                puts(POPQ("%rax"));
                break;
            // TODO: Implement
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            }
        }
    }
}

static void gen_assignment(symbol_t *func, node_t *node) {
    switch (node->type) {
    case ASSIGNMENT_STATEMENT:
        gen_expr(func, node->children[1]);
        printf("\tmovq %%rax, ");
        gen_ident(func, node->children[0]);
        putchar('\n');
        break;
    case ADD_STATEMENT:
        gen_expr(func, node->children[1]);
        printf("\taddq %%rax, ");
        gen_ident(func, node->children[0]);
        putchar('\n');
        break;
    case SUBTRACT_STATEMENT:
        gen_expr(func, node->children[1]);
        printf("\tsubq %%rax, ");
        gen_ident(func, node->children[0]);
        putchar('\n');
        break;
    case MULTIPLY_STATEMENT:
        gen_expr(func, node->children[1]);
        printf("\tmulq ");
        gen_ident(func, node->children[0]);
        printf("\n\tmovq %%rax, ");
        gen_ident(func, node->children[0]);
        putchar('\n');
        break;
    case DIVIDE_STATEMENT:
        gen_expr(func, node->children[1]);
        printf("\txchgq %%rax, ");
        gen_ident(func, node->children[0]);
        printf("\n\tcgo\n"
               "\tidivq ");
        gen_ident(func, node->children[0]);
        printf("\n\txchq %%rax, ");
        gen_ident(func, node->children[0]);
        putchar('\n');
        break;
    default:
        ICE("invalid assignment statement");
        break;
    }
}

static void gen_print(symbol_t *func, node_t *node) {
    for (size_t i = 0; i < node->n_children; i++) {
        node_t *arg = node->children[i];
        switch (arg->type) {
        case STRING_DATA:
            puts(MOVQ("$.strout", "%rdi"));
            printf(MOVQ("$.STR%zu", "%%rsi") "\n", *(size_t *)arg->data);
            break;
        case NUMBER_DATA:
            puts(MOVQ("$.intout", "%rdi"));
            printf(MOVQ("$%ld", "%%rsi") "\n", *(int64_t *)arg->data);
            break;
        case IDENTIFIER_DATA:
            puts(MOVQ("$.intout", "%rdi"));
            printf("\tmovq ");
            gen_ident(func, arg);
            puts(", %rsi");
            break;
        case EXPRESSION:
            gen_expr(func, arg);
            puts(MOVQ("$.intout", "%rdi"));
            puts(MOVQ("%rax", "%rsi"));
            break;
        default:
            ICE("invalid print statement");
            break;
        }

        puts(MOVQ("$0", "%rax"));
        puts(CALL("printf"));
    }

    puts(MOVQ("$0x0A", "%rdi"));
    puts(CALL("putchar"));
}

void generate_node(symbol_t *func, node_t *node) {
    switch (node->type) {
    case PRINT_STATEMENT:
        gen_print(func, node);
        break;
    case ASSIGNMENT_STATEMENT:
    case ADD_STATEMENT:
    case SUBTRACT_STATEMENT:
    case MULTIPLY_STATEMENT:
    case DIVIDE_STATEMENT:
        gen_assignment(func, node);
        break;
    case RETURN_STATEMENT:
        gen_expr(func, node->children[0]);
        puts(LEAVE);
        puts(RET);
        break;
    case IF_STATEMENT:
    case WHILE_STATEMENT:
    case NULL_STATEMENT:
        // Not implemented
        break;
    default:
        for (size_t i = 0; i < node->n_children; i++) {
            generate_node(func, node->children[i]);
        }
        break;
    }
}

/**Generates the main function with argument parsing and calling of our
 * main function (first, if no function is named main)
 * @param first Symbol table entry of our main function */
void generate_main(symbol_t *first) {
    puts(".globl main");
    puts(".section .text");
    puts("main:");
    puts("\tpushq   %rbp");
    puts("\tmovq    %rsp, %rbp");

    printf("\tsubq\t$1,%%rdi\n");
    printf("\tcmpq\t$%zu,%%rdi\n", first->nparms);
    printf("\tjne\tABORT\n");
    printf("\tcmpq\t$0,%%rdi\n");
    printf("\tjz\tSKIP_ARGS\n");

    printf("\tmovq\t%%rdi,%%rcx\n");
    printf("\taddq $%zu, %%rsi\n", 8 * first->nparms);
    printf("PARSE_ARGV:\n");
    printf("\tpushq %%rcx\n");
    printf("\tpushq %%rsi\n");

    printf("\tmovq\t(%%rsi),%%rdi\n");
    printf("\tmovq\t$0,%%rsi\n");
    printf("\tmovq\t$10,%%rdx\n");
    printf("\tcall\tstrtol\n");

    /*  Now a new argument is an integer in rax */

    printf("\tpopq %%rsi\n");
    printf("\tpopq %%rcx\n");
    printf("\tpushq %%rax\n");
    printf("\tsubq $8, %%rsi\n");
    printf("\tloop PARSE_ARGV\n");

    /* Now the arguments are in order on stack */
    for (int arg = 0; arg < MIN(6, first->nparms); arg++)
        printf("\tpopq\t%s\n", record[arg]);

    printf("SKIP_ARGS:\n");
    printf("\tcall\t_%s\n", first->name);
    printf("\tjmp\tEND\n");
    printf("ABORT:\n");
    printf("\tmovq\t$.errout, %%rdi\n");
    printf("\tcall puts\n");

    printf("END:\n");
    puts("\tmovq    %rax, %rdi");
    puts("\tcall    exit");
}
