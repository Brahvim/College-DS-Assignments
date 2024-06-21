#include <stdio.h>

#include "BinaryIntNode.h"

#define MAKE_OUR_NODE(name)                                         \
MAKE_BINARY_NODE_HANDLING_ALL(int, name, name##_node_error, {       \
	puts("Could not allocate for tree node, \"`" #name "`\".");   	\
	exit(EXIT_FAILURE);                                             \
});																	\
																	\

int main() {
	MAKE_OUR_NODE(tree); // Root node!

	MAKE_OUR_NODE(left);

	MAKE_OUR_NODE(right);

	tree->left = left;
	tree->right = right;

	// Pre-order traversal of our three-node tree ("root-left-right"!):

#define PRINT_NODE_INFO(node) printf("`%zu`. [%p]: `%d`.\n", ++i, node, node->data = i); /* NOLINT(clang-diagnostic-unsequenced) */

	size_t i = 0;
	puts("Pre-order traversal:");

	PRINT_NODE_INFO(tree);
	PRINT_NODE_INFO(left);
	PRINT_NODE_INFO(right);

#undef PRINT_NODE_INFO

	// Post-order traversal for tree deletion ("left-right-root"!):
	free(left);
	free(right);
	free(tree);
}

#undef MAKE_OUR_NODE
