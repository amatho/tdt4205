#include <vslc.h>

static void node_print(node_t *root, int nesting);
static void simplify_tree(node_t **simplified, node_t *root);
static void node_finalize(node_t *discard);

typedef struct stem_t *stem;
struct stem_t {
    const char *str;
    stem next;
};
static void tree_print(node_t *root, stem head);

static void destroy_subtree(node_t *discard);

/* External interface */
void destroy_syntax_tree(void) { destroy_subtree(root); }

void simplify_syntax_tree(void) { simplify_tree(&root, root); }

extern bool new_print_style;
void print_syntax_tree(void) {
    if (new_print_style)
        tree_print(root, 0);
    // Old tree printing
    else
        node_print(root, 0);
}

void node_init(node_t *nd, node_index_t type, void *data, uint64_t n_children,
               ...) {
    va_list child_list;
    *nd =
        (node_t){.type = type,
                 .data = data,
                 .entry = NULL,
                 .n_children = n_children,
                 .children = (node_t **)malloc(n_children * sizeof(node_t *))};
    va_start(child_list, n_children);
    for (uint64_t i = 0; i < n_children; i++)
        nd->children[i] = va_arg(child_list, node_t *);
    va_end(child_list);
}

static void tree_print(node_t *root, stem head) {
    static const char *sdown = " │", *slast = " └", *snone = "  ";
    struct stem_t col = {0, 0}, *tail;

    // Print stems of branches coming further down
    for (tail = head; tail; tail = tail->next) {
        if (!tail->next) {
            if (!strcmp(sdown, tail->str))
                printf(" ├");
            else
                printf("%s", tail->str);
            break;
        }
        printf("%s", tail->str);
    }

    if (root == NULL) {
        // Secure against null pointers sent as root
        printf("─(nil)\n");
        return;
    }
    printf("─%s", node_string[root->type]);
    if (root->type == IDENTIFIER_DATA || root->type == STRING_DATA ||
        root->type == EXPRESSION)
        printf("(%s)", (char *)root->data);
    else if (root->type == NUMBER_DATA)
        printf("(%ld)", *((int64_t *)root->data));
    putchar('\n');

    if (!root->n_children)
        return;

    if (tail && tail->str == slast)
        tail->str = snone;

    if (!tail)
        tail = head = &col;
    else
        tail->next = &col;

    for (int64_t i = 0; i < root->n_children; i++) {
        col.str = root->n_children - i - 1 ? sdown : slast;
        tree_print(root->children[i], head);
    }
    tail->next = 0;
}

/* Internal choices */
static void node_print(node_t *root, int nesting) {
    if (root != NULL) {
        printf("%*c%s", nesting, ' ', node_string[root->type]);
        if (root->type == IDENTIFIER_DATA || root->type == STRING_DATA ||
            root->type == EXPRESSION)
            printf("(%s)", (char *)root->data);
        else if (root->type == NUMBER_DATA)
            printf("(%ld)", *((int64_t *)root->data));
        putchar('\n');
        for (int64_t i = 0; i < root->n_children; i++)
            node_print(root->children[i], nesting + 1);
    } else
        printf("%*c%p\n", nesting, ' ', root);
}

static void node_finalize(node_t *discard) {
    if (discard != NULL) {
        free(discard->data);
        free(discard->children);
        free(discard);
    }
}

static void destroy_subtree(node_t *discard) {
    if (discard != NULL) {
        for (uint64_t i = 0; i < discard->n_children; i++)
            destroy_subtree(discard->children[i]);
        node_finalize(discard);
    }
}

node_t *prune_children(node_t *root) {
    if (root->type == PRINT_STATEMENT) {
        node_t *node = root->children[0];
        root->n_children = node->n_children;
        free(root->children);
        root->children = node->children;
        node->children = NULL;
        node_finalize(node);

        for (uintptr_t i = 0; i < root->n_children; i++) {
            node_t *child = root->children[i];
            root->children[i] = child->children[0];
            node_finalize(child);
        }
    } else if (root->type == PROGRAM) {
        for (uintptr_t i = 0; i < root->children[0]->n_children; i++) {
            node_t *child = root->children[0]->children[i];
            root->children[0]->children[i] = child->children[0];
            node_finalize(child);
        }
    } else if (root->type == PARAMETER_LIST || root->type == ARGUMENT_LIST ||
               root->type == STATEMENT) {
        node_t *child = root->children[0];
        node_finalize(root);
        root = child;
    } else if (root->type == EXPRESSION && root->n_children == 1 &&
               root->data == NULL &&
               root->children[0]->type == IDENTIFIER_DATA) {
        node_t *child = root->children[0];
        node_finalize(root);
        root = child;
    }

    return root;
}

static void resolve_constant_expressions(node_t *root) {
    if (root->type == EXPRESSION) {
        bool is_const = 1;
        for (uintptr_t i = 0; i < root->n_children; i++) {
            if (root->children[i]->type != NUMBER_DATA) {
                is_const = 0;
            }
        }

        if (is_const) {
            int64_t *val = malloc(sizeof(int64_t));
            if (root->data == NULL) {
                *val = *(int64_t *)root->children[0]->data;
            } else if (strcmp(root->data, "+") == 0) {
                *val = *(int64_t *)root->children[0]->data +
                       *(int64_t *)root->children[1]->data;
            } else if (strcmp(root->data, "-") == 0) {
                if (root->n_children == 1) {
                    *val = -(*(int64_t *)root->children[0]->data);
                } else {
                    *val = *(int64_t *)root->children[0]->data -
                           *(int64_t *)root->children[1]->data;
                }
            } else if (strcmp(root->data, "*") == 0) {
                *val = *(int64_t *)root->children[0]->data *
                       *(int64_t *)root->children[1]->data;
            } else if (strcmp(root->data, "/") == 0) {
                *val = *(int64_t *)root->children[0]->data /
                       *(int64_t *)root->children[1]->data;
            }

            for (uintptr_t i = 0; i < root->n_children; i++) {
                destroy_subtree(root->children[i]);
            }

            free(root->children);
            root->children = NULL;
            root->n_children = 0;
            free(root->data);
            root->data = val;
            root->type = NUMBER_DATA;
        }
    }
}

bool is_list(node_t *node) {
    switch (node->type) {
    case GLOBAL_LIST:
        return 1;
    case STATEMENT_LIST:
        return 1;
    case PRINT_LIST:
        return 1;
    case EXPRESSION_LIST:
        return 1;
    case VARIABLE_LIST:
        return 1;
    case ARGUMENT_LIST:
        return 1;
    case PARAMETER_LIST:
        return 1;
    case DECLARATION_LIST:
        return 1;
    default:
        return 0;
    }
}

static void flatten(node_t *root) {
    if (is_list(root) && root->n_children >= 1) {
        if (root->children[0]->type == root->type) {
            node_t *child_list = root->children[0];
            node_t **new_array = (node_t **)realloc(
                child_list->children,
                (child_list->n_children + 1) * sizeof(node_t *));

            if (new_array == NULL) {
                fprintf(stderr, "Error: could not reallocate memory");
                exit(1);
            }

            child_list->children = NULL;
            new_array[child_list->n_children] = root->children[1];
            root->n_children = child_list->n_children + 1;
            root->children = new_array;
            node_finalize(child_list);
        }
    }
}

static void simplify_tree(node_t **simplified, node_t *root) {
    for (uintptr_t i = 0; i < root->n_children; i++) {
        if (root->children[i] != NULL) {
            simplify_tree(&root->children[i], root->children[i]);
        }
    }

    root = prune_children(root);
    resolve_constant_expressions(root);
    flatten(root);
    *simplified = root;
}
