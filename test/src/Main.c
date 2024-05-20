#include <stdio.h>

#include "SinglyLinkedIntNode.h"

int main() {
    MAKE_SINGLY_LINKED_NODE_HANDLING_ALL(int, list, list_init_error, {
        puts("Allocating the entire list failed!");
        exit(EXIT_FAILURE);
    });

    // I will abstract this to a function only when I get around to make a
    // `create_contiguous_singly_linked_##type##_list()` function.

    struct singly_linked_int_node *previous_node = list;
    puts("Allocating nodes!:\n");
    for (size_t i = 1; i < 5; ++i) {
        MAKE_SINGLY_LINKED_NODE_HANDLING_ALL(int, current_node, node_init_error, {
            puts("Allocating some node failed :|");
            exit(EXIT_FAILURE);
        });

        printf("Previous: [%p], current: [%p].\n", previous_node, current_node);
        previous_node->next = current_node;
        previous_node = current_node;
    }
    puts("\n...Done allocating!\n");

    puts("List data:");
    {
        size_t i = 0;
        TRAVERSE_SINGLY_LINKED_LIST(int, list, node, printf("[%p]: `%d`\n", node, node->data = ++i));
    }

    struct singly_linked_int_node *head = list;
    list = list->next;
    free(head);

    puts("\n...After removing the head node:");
    TRAVERSE_SINGLY_LINKED_LIST(int, list, node, printf("[%p]: `%d`\n", node, node->data));

    destroy_singly_linked_int_list(list);
}
