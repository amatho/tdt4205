#include "ir.h"
#include "tlhash.h"
#include <malloc/_malloc.h>
#include <stdio.h>
#include <vslc.h>

// Externally visible, for the generator
extern tlhash_t *global_names;
extern char **string_list;
extern size_t n_string_list, stringc;

tlhash_t **local_scopes = NULL;
size_t scope_cap = 1;
size_t scope_len;

// Implementation choices, only relevant internally
static void find_globals(void);
/** @param function Function's symbol table entry
 *  @param root Function's root node */
static void bind_names(symbol_t *function, node_t *root);

void create_symbol_table(void) {
    global_names = malloc(sizeof(tlhash_t));
    tlhash_init(global_names, 64);
    string_list = malloc(n_string_list * sizeof(char *));

    find_globals();

    size_t global_count = tlhash_size(global_names);
    symbol_t *globals[global_count];
    tlhash_values(global_names, (void **)&globals);
    for (ptrdiff_t i = 0; i < global_count; i++) {
        if (globals[i]->type == SYM_FUNCTION) {
            bind_names(globals[i], globals[i]->node);
        }
    }
}

static void print_symbols(tlhash_t *table, char *parent_name) {

    size_t size = tlhash_size(table);
    symbol_t *symbols[size];
    tlhash_values(table, (void **)symbols);

    for (ptrdiff_t i = 0; i < size; i++) {
        printf("in scope '%s', symbol with name '%s' (seq: %d)\n", parent_name,
               symbols[i]->name, symbols[i]->seq);
        if (symbols[i]->type == SYM_FUNCTION) {
            print_symbols(symbols[i]->locals, symbols[i]->name);
        }
    }
}

void print_symbol_table(void) {
    printf("Symbol table:\n");
    print_symbols(global_names, "Global");
}

void destroy_symbol_table(void) {
    for (ptrdiff_t i = 0; i < stringc; i++) {
        free(string_list[i]);
    }

    free(string_list);

    size_t global_count = tlhash_size(global_names);
    symbol_t *global_names_values[global_count];
    tlhash_values(global_names, (void **)&global_names_values);

    for (ptrdiff_t i = 0; i < global_count; i++) {
        symbol_t *global = global_names_values[i];
        if (global->locals != NULL) {
            size_t local_count = tlhash_size(global->locals);
            symbol_t *local_values[local_count];
            tlhash_values(global->locals, (void **)&local_values);

            for (ptrdiff_t j = 0; j < local_count; j++) {
                free(local_values[j]);
            }

            tlhash_finalize(global->locals);
            free(global->locals);
        }

        free(global);
    }

    tlhash_finalize(global_names);
    free(global_names);
    free(local_scopes);
}

void find_globals(void) {
    size_t function_count = 0;
    node_t *global_list = root->children[0];

    for (ptrdiff_t i = 0; i < global_list->n_children; i++) {
        node_t *global = global_list->children[i];

        if (global->type == FUNCTION) {
            symbol_t *symbol = malloc(sizeof(symbol_t));
            *symbol = (symbol_t){.type = SYM_FUNCTION,
                                 .name = global->children[0]->data,
                                 .node = global->children[2],
                                 .seq = function_count,
                                 .nparms = 0,
                                 .locals = malloc(sizeof(tlhash_t))};
            function_count++;

            tlhash_init(symbol->locals, 32);
            if (global->children[1] != NULL) {
                symbol->nparms = global->children[1]->n_children;
                for (ptrdiff_t j = 0; j < symbol->nparms; j++) {
                    node_t *param = global->children[1]->children[j];
                    symbol_t *param_sym = malloc(sizeof(symbol_t));
                    *param_sym = (symbol_t){.type = SYM_PARAMETER,
                                            .name = param->data,
                                            .node = NULL,
                                            .seq = j,
                                            .nparms = 0,
                                            .locals = NULL};
                    tlhash_insert(symbol->locals, param_sym->name,
                                  strlen(param_sym->name), param_sym);
                }
            }

            tlhash_insert(global_names, symbol->name, strlen(symbol->name),
                          symbol);
        } else if (global->type == DECLARATION) {
            node_t *name_list = global->children[0];
            for (ptrdiff_t j = 0; j < name_list->n_children; j++) {
                symbol_t *symbol = malloc(sizeof(symbol_t));
                *symbol = (symbol_t){.type = SYM_GLOBAL_VAR,
                                     .name = name_list->children[j]->data,
                                     .node = NULL,
                                     .seq = 0,
                                     .nparms = 0,
                                     .locals = NULL};
                tlhash_insert(global_names, symbol->name, strlen(symbol->name),
                              symbol);
            }
        }
    }
}

static void local_scope_push() {
    if (local_scopes == NULL) {
        local_scopes = malloc(scope_cap * sizeof(tlhash_t *));
    }

    tlhash_t *new_scope = malloc(sizeof(tlhash_t));
    tlhash_init(new_scope, 32);
    local_scopes[scope_len] = new_scope;

    scope_len += 1;
    if (scope_len >= scope_cap) {
        scope_cap *= 2;
        local_scopes = realloc(local_scopes, scope_cap * sizeof(tlhash_t *));
    }
}

static void local_scope_pop() {
    scope_len -= 1;
    tlhash_finalize(local_scopes[scope_len]);
    free(local_scopes[scope_len]);
    local_scopes[scope_len] = NULL;
}

void bind_names(symbol_t *function, node_t *root) {
    if (root == NULL) {
        return;
    } else {
        node_t *name_list;
        symbol_t *entry;
        switch (root->type) {
        case BLOCK:
            local_scope_push();

            for (ptrdiff_t i = 0; i < root->n_children; i++) {
                bind_names(function, root->children[i]);
            }

            local_scope_pop();
            break;
        case DECLARATION:
            name_list = root->children[0];
            for (ptrdiff_t i = 0; i < name_list->n_children; i++) {
                node_t *var_name = name_list->children[i];
                size_t local_count =
                    tlhash_size(function->locals) - function->nparms;

                symbol_t *symbol = malloc(sizeof(symbol_t));
                *symbol = (symbol_t){.type = SYM_LOCAL_VAR,
                                     .name = var_name->data,
                                     .node = NULL,
                                     .seq = local_count,
                                     .nparms = 0,
                                     .locals = NULL};

                tlhash_insert(function->locals, &local_count, sizeof(size_t),
                              symbol);
                tlhash_insert(local_scopes[scope_len - 1], symbol->name,
                              strlen(symbol->name), symbol);
            }
            break;
        case IDENTIFIER_DATA:
            entry = NULL;
            size_t idx = scope_len;
            while (entry == NULL && idx > 0) {
                idx -= 1;
                tlhash_lookup(local_scopes[idx], root->data, strlen(root->data),
                              (void **)&entry);
            }

            if (entry == NULL) {
                tlhash_lookup(function->locals, root->data, strlen(root->data),
                              (void **)&entry);
            }

            if (entry == NULL) {
                tlhash_lookup(global_names, root->data, strlen(root->data),
                              (void **)&entry);
            }

            if (entry == NULL) {
                fprintf(stderr, "identifier '%s' was not found\n",
                        (char *)root->data);
                exit(EXIT_FAILURE);
            }

            root->entry = entry;
            break;
        case STRING_DATA:
            string_list[stringc] = root->data;
            root->data = malloc(sizeof(size_t));
            *(size_t *)root->data = stringc;
            stringc += 1;

            if (stringc >= n_string_list) {
                n_string_list *= 2;
                string_list =
                    realloc(string_list, n_string_list * sizeof(char *));
            }
            break;
        default:
            for (ptrdiff_t i = 0; i < root->n_children; i++) {
                bind_names(function, root->children[i]);
            }
            break;
        }
    }
}
