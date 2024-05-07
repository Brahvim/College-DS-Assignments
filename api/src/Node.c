#include <stdlib.h>

#include "Node.h"

enum node_status create_node(struct singly_linked_node **p_node) {
    *p_node = malloc(sizeof(struct singly_linked_node));

    if (!(*p_node))
        return NODE_STATUS_MALLOC;

    (*p_node)->data = 0;
    (*p_node)->next = NULL;

    return NODE_STATUS_NO_ERROR;
}

enum node_status destroy_node(struct singly_linked_node *p_previous, struct singly_linked_node *p_to_free) {
    // ...It's an assignment requirement to use singly-linked nodes, LOL:
    if (p_previous && p_to_free)
        p_previous->next = p_to_free->next;

    free(p_to_free);
}

enum node_status destroy_linked_list(struct singly_linked_node *p_first_node) {
    if (!p_first_node)
        return NODE_STATUS_NULL;

    struct singly_linked_node *current = p_first_node;

    while (current) {
        struct singly_linked_node *next = current->next;
        free(current);
        current = next;
    }

    return NODE_STATUS_NO_ERROR;
}

enum node_status insert_node_in_linked_list(struct singly_linked_node *p_node) {

}

enum node_status create_contiguous_linked_list(struct singly_linked_node **p_first_node, size_t p_list_length) {

}

