#include <stdlib.h>

#include "Node.h"

enum node_status create_node(struct singly_linked_node **p_node) {
    *p_node = malloc(sizeof(struct singly_linked_node));

    if (!(*p_node))
        return NODE_STATUS_MALLOC;

    (*p_node)->next = NULL;
    (*p_node)->data = 0;

    return NODE_STATUS_NO_ERROR;
}

enum node_status destroy_node(struct singly_linked_node *p_previous, struct singly_linked_node *p_to_free) {
    p_previous->next = p_to_free->next;
    free(p_to_free);
}

enum node_status destroy_linked_list(struct singly_linked_node *p_first_node) {

}

enum node_status insert_node_in_linked_list(struct singly_linked_node *p_node) {

}

enum node_status create_contiguous_linked_list(struct singly_linked_node **p_first_node, size_t p_list_length) {

}

