#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Main.h"

int main() {
	size_t expr_len;
	const char *expr = read_line(5, &expr_len);
	++expr_len;

	printf("Expression length: `%zu`.\n", expr_len);

	MAKE_STACK_HANDLING_ALL(char, stack, 0, {
		puts("Failed to allocate for `stack`...\n");
		exit(EXIT_FAILURE);
	});

	double result = 0;
	for (size_t i = 0; i < expr_len; ++i) {
		const unsigned char c = expr[i];

		// `47` is `'0'`, and `57` is `'9'`:
		if (c > 47 && c < 58) {
			// ...We have a number.
		} else // ...We have some operand.
			switch (c) {
				case POSTFIX_ADD: {
				}

				case POSTFIX_DIVIDE: {
				}

				case POSTFIX_MODULO: {
				}

				case POSTFIX_MULTIPLY: {
				}

				case POSTFIX_SUBTRACT: {
				}

				default: {
					puts("Ooops! Encountered unknown character! Exiting now...");
					exit(EXIT_FAILURE);
				}
			}
	}

	printf("Result: `%lf`.\n", result);
}

/**
 * [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ],
 * [ https://github.com/Brahvim/College-C-Assignments/blob/26934f9777473ebb2a759f2f17f9715820ffa46f/ReadLine.c#L7 ].
 */
void clear_stdin(void) {
	// Correction from last semester's version - I should've used an `int`!
	for (int c; !((c = getchar()) == '\n' || c == EOF);)	// FlawFinder: Ignore. Why? Because I don't know any boundary either!
		;													// Just trying to clear a buffer, dear linter.
}

char* read_line(const size_t p_factor, size_t *p_out_size) {
	size_t size = 5; // ...Buffer's current size?
	size_t read_size = 0; // How filled is the buffer?!
	char *line = malloc(size);

	if (!line) {
		perror("`read_line()` failed to allocate memory.");
		return NULL;
	}

	for (int c = fgetc(stdin); !(c == EOF || c == '\n'); c = fgetc(stdin)) { // FlawFinder: Ignore. We can't do it here either...
		line[read_size] = c;
		++read_size;

		if (read_size == size) {
			size += p_factor;
			char *reallocated = realloc(line, size);

			if (!reallocated) {
				perror("`read_line()` failed to re-allocate memory.");
				return line;
			}

			line = reallocated;
		}
	}

	// Tell 'em the size. TELL 'EM!:
	*p_out_size = read_size;

	// We re-allocate to make sure we have a string of the perfect size:
	line = realloc(line, read_size + 1);
	line[read_size] = '\0';

	return line;
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

void string_to_stack(const char *p_string, struct char_stack *p_stack) {
	for (int i = 0; i < p_stack->fits; ++i)
		char_stack_push(p_stack, p_string[i]);
}
