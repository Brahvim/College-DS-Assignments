#include <stdio.h>

#include "SinglyLinkedIntNode.h"

int main() {
    MAKE_NODE_HANDLING_ALL(int, list, error, {});

    // I will abstract this to a function only when I get around to make a
    // `create_contiguous_singly_linked_##type##_list()` function.
    struct singly_linked_int_node *previous_node = list;
    for (size_t i = 0; i < 5; i++) {
        MAKE_NODE_HANDLING_ALL(int, current_node, error, {});
        previous_node->data = i;
        previous_node->next = current_node;
        previous_node = current_node;
    }

    for (struct singly_linked_int_node *node = list; node->next != NULL; node = node->next)
        printf("%d\n", node->data);

    destroy_singly_linked_int_list(list);
}
