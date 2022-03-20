#ifndef IR_H
#define IR_H

#include "nodetypes.h"
#include "tlhash.h"
#include <inttypes.h>
#include <stddef.h>

/* This is the tree node structure */
typedef struct n {
    node_index_t type;
    void *data;
    struct s *entry;
    uint64_t n_children;
    struct n **children;
} node_t;

// Export the initializer function, it is needed by the parser
void node_init (
    node_t *nd, node_index_t type, void *data, uint64_t n_children, ...
);

typedef enum {
    SYM_GLOBAL_VAR, SYM_FUNCTION, SYM_PARAMETER, SYM_LOCAL_VAR
} symtype_t;

typedef struct s {
    char *name;
    symtype_t type;
    node_t *node;
    size_t seq;
    size_t nparms;
    tlhash_t *locals;
} symbol_t;

// typedef struct symboltable {
//     tlhash_t *hashmaps[20];
//     size_t hashmap_count;
//     symbol_t **symbols;
//     size_t symbols_size;
//     size_t symbols_capacity;
//     node_t *func_node;
// } symboltable_t;

// extern symboltable_t global_table;
#endif
