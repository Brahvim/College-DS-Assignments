#include <stdio.h>
#include <stdlib.h>

#include "Main.h"

int main() {
	// Create a stack with an initial allocation size for `10` `int`s:
	MAKE_STACK_HANDLING_ALL(int, stack, 10, {
		puts("Failed to create the stack.\n");
		exit(EXIT_FAILURE);
	});

	// Push `500` elements onto the stack:
	for (int i = 1; i <= 500; ++i) {
		if (STACK_ERROR(int_stack_push(stack, i)))
			printf("Failed to push `%d` onto the stack.\n", i);
		else
			printf("Pushed `%d` onto the stack.\n", i);
	}

	puts("\nPushed it all!\n");

	// Pop elements from the stack until it's empty:
	for (int i; STACK_NO_ERROR(int_stack_poll(stack, &i));)
		printf("Popped `%d` from the stack.\n", i);

	// Destroy the stack when done:
	int_stack_destroy(stack);
}
