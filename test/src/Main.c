#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

#define ORIGINAL_STRING "Brahvim"
#define ORIGINAL_STRING_SIZE sizeof(ORIGINAL_STRING) / sizeof(char)

int main() {
	char *name = calloc(ORIGINAL_STRING_SIZE, sizeof(char));
	strncpy(name, "Brahvim", ORIGINAL_STRING_SIZE);

	MAKE_STACK(char, stack, sizeof(name), {
		puts("Failed to create the stack.\n");
		return EXIT_FAILURE;
	});

	char *reversed = calloc(8, sizeof(char));

	string_to_stack(name, stack);
	reverse_char_stack(stack);
	stack_to_string(stack, reversed);

	puts("Reversed string:");
	printf("%s", reversed + sizeof(char));

	free(reversed);

	// Destroy the stack when done:
	char_stack_destroy(stack);
}

int char_compare_fxn(const void *p_first, const void *p_second) {
	const int result = (int)(p_first - p_second);
	return result < 0 ? -1 :
		result == 0 ? 0 : 1;
	// return p_first - p_second;
}

void reverse_char_stack(struct char_stack *p_stack) {
	qsort(p_stack->array, p_stack->fits, sizeof(char), char_compare_fxn);
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
