#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

#define ORIGINAL_STRING ((char*)"Brahvim")
#define ORIGINAL_STRING_SIZE (sizeof(ORIGINAL_STRING) * sizeof(char))
#define ORIGINAL_STRING_LENGTH (sizeof(ORIGINAL_STRING) / sizeof(char))

int main() {
	MAKE_STACK(char, stack, ORIGINAL_STRING_SIZE, {
		puts("Failed to allocate for `stack`.\n");
		return EXIT_FAILURE;
	});

	MAKE_STACK(char, reversed_stack, ORIGINAL_STRING_SIZE, {
		puts("Failed to allocate for `reversed_stack`.\n");
		return EXIT_FAILURE;
	});

	char *reversed_string = malloc(ORIGINAL_STRING_SIZE);

	string_to_stack(ORIGINAL_STRING, stack);

	char c;
	while (STACK_NO_ERROR(char_stack_poll(stack, &c)))
		char_stack_push(reversed_stack, c);

	stack_to_string(reversed_stack, reversed_string);

	puts("Reversed string:");
	printf("%s", reversed_string);

	// No leaks here!:
	free(reversed_string);
	char_stack_destroy(stack);
	char_stack_destroy(reversed_stack);
}

int char_compare_fxn(const void *p_first, const void *p_second) {
	const int result = (int)(p_first - p_second);
	return result < 0 ? -1 :
		result == 0 ? 0 : 1;
	// return p_first - p_second;
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
