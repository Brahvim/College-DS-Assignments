#include <stdio.h>

#include "BinaryIntNode.h"

int main() {
    MAKE_BINARY_NODE_HANDLING_ALL(int, tree, head_node_error, {
        puts("Could not allocate for tree head.");
        exit(EXIT_FAILURE);
    });

    MAKE_BINARY_NODE_HANDLING_ALL(int, left_node, left_node_error, {
        puts("Could not allocate for some left node.");
        exit(EXIT_FAILURE);
    });

    MAKE_BINARY_NODE_HANDLING_ALL(int, right_node, right_node_error, {
        puts("Could not allocate for some right node.");
        exit(EXIT_FAILURE);
    });

    tree->left = left_node;
    tree->right = right_node;

    tree->right->data = 1;
    tree->left->data = 2;
    tree->data = 3;

    free(tree->right);
    free(tree->left);
    free(tree);
}
