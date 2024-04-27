#include <stdio.h>
#include <stdlib.h>

#include "Main.h"

int main() {
	// Create a stack with an initial allocation size for `10` `int`s:
	struct int_stack *stack = int_stack_create(10);
	if (stack == NULL) {
		puts("Failed to create the stack.\n");
		return EXIT_FAILURE;
	}

	// Push some elements onto the stack:
	for (int i = 1; i < 16; ++i) {
		if (!int_stack_push(stack, i))
			printf("Failed to push `%d` onto the stack.\n", i);
		else
			printf("Pushed `%d` onto the stack.\n", i);
	}

	// Pop elements from the stack until it's empty
	while (int_stack_pop(stack))
		printf("Popped an element from the stack.\n");

	// Destroy the stack when done
	int_stack_destroy(stack);
}
