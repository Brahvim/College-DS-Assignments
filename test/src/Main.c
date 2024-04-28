#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

#define ORIGINAL_STRING ((char*)"Brahvim")
#define ORIGINAL_STRING_SIZE (sizeof(ORIGINAL_STRING) * sizeof(char))
#define ORIGINAL_STRING_LENGTH (sizeof(ORIGINAL_STRING) / sizeof(char))

int main() {
	MAKE_STACK_HANDLING_ALL(char, stack, ORIGINAL_STRING_SIZE, {
		puts("Failed to allocate for `stack`.\n");
		return EXIT_FAILURE;
	});

	// MAKE_STACK_HANDLING_ALL(char, reversed_stack, ORIGINAL_STRING_SIZE, {
	// 	puts("Failed to allocate for `reversed_stack`.\n");
	// 	return EXIT_FAILURE;
	// });

	string_to_stack(ORIGINAL_STRING, stack);

	// char c;
	// stack_status s;
	// while (STACK_NO_ERROR(s = char_stack_poll(stack, &c))) {
	// 	printf("Character read: `%c`\n", c);
	// 	printf("Poll state: `%d`\n", s);
	// 	s = char_stack_push(reversed_stack, c);
	// 	printf("Push state: `%d`\n", s);
	// }

	char *reversed_string = malloc(ORIGINAL_STRING_SIZE);
	stack_to_string(stack, reversed_string);
	// stack_to_string(reversed_stack, reversed_string);
	printf("Reversed string: \"%s\"\n", reversed_string);

	// No leaks here!:
	free(reversed_string);
	char_stack_destroy(stack);
	// char_stack_destroy(reversed_stack);
}

void string_to_stack(const char *p_string, struct char_stack *p_stack) {
	for (int i = 0; i < p_stack->fits; ++i)
		char_stack_push(p_stack, p_string[i]);
}

void stack_to_string(struct char_stack *p_stack, char *p_string) {
	char c;
	stack_status s;
	int counter = 0;
	char_stack_pop(p_stack); // C-strings, well, they have a `\0` at the end...

	while (STACK_NO_ERROR(s = char_stack_poll(p_stack, &c)))
		p_string[counter++] = c;

	p_string[counter] = '\0';
}
