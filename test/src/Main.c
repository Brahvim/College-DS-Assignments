#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

int main() {
	char *name = calloc(8, sizeof(char));
	strncpy(name, "Brahvim", 8);

	MAKE_STACK(char, stack, sizeof(name), {
		puts("Failed to create the stack.\n");
		return EXIT_FAILURE;
	});

	char *reversed = calloc(8, sizeof(char));

	string_to_stack(name, stack);
	reverse_char_stack(stack);
	stack_to_string(stack, reversed);

	puts("Reversed string:");

	for (size_t i = 7; i > 0; --i)
		putc(reversed[i], stdout);

	free(reversed);

	// Destroy the stack when done:
	char_stack_destroy(stack);
}

void reverse_char_stack(struct char_stack *p_stack) {
	if (!char_stack_is_empty(p_stack)) {
		char temp = char_stack_pop(p_stack);
		reverse_char_stack(p_stack);

		insert_at_char_stack_bottom(p_stack, temp);
	}
}

void string_to_stack(char *p_string, struct char_stack *p_stack) {
	for (int i = 0; i < p_stack->fits; ++i)
		char_stack_push(p_stack, p_string[i]);
}

void stack_to_string(struct char_stack *p_stack, char *p_string) {




	char c;
	int counter = 0;
	while (STACK_NO_ERROR(char_stack_poll(p_stack, &c)))
		p_string[counter++] = c;

	p_string[counter] = '\0';
}

void insert_at_char_stack_bottom(struct char_stack *p_stack, char p_item) {
	if (char_stack_is_empty(p_stack)) {
		char_stack_push(p_stack, p_item);
	} else {
		char temp = char_stack_pop(p_stack);
		insert_at_char_stack_bottom(p_stack, p_item);
		char_stack_push(p_stack, temp);
	}
}
