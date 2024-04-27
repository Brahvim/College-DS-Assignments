#include <stdio.h>
#include <stdlib.h>

#include "Main.h"

int main() {
	// Create a stack with an initial allocation size for `10` `int`s:
	MAKE_STACK(char, stack, 10, {
		puts("Failed to create the stack.\n");
		return EXIT_FAILURE;
	});



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
	char c;
	while (STACK_NO_ERROR(c = char_stack_poll(p_stack)))
		;



}

void stack_to_string(struct char_stack *p_stack, char *p_string) {

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
