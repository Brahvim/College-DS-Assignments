#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "Main.h"

int main() {
	size_t expr_len = 0;
	expr_char_t *expr = read_line(5, &expr_len);
	++expr_len;

	printf("Expression length: `%zu`.\n", expr_len);

	stack_status operand_stack_status;
	MAKE_STACK_HANDLING_ALL(double, operand_stack, 0, {
		puts("Failed to allocate for `operand_stack`...\n");
		exit(EXIT_FAILURE);
	});

	expr_char_t c = 0;
	double result = 0;
	size_t expr_chars_processed = 0;

	for (expr_char_t *expr_char_ptr = expr; (c = *expr_char_ptr) != '\0'; expr_char_ptr += sizeof(expr_char_t)) {
		// Absolutely ignore whitespaces:
		if (c == ' ' || c == '\t')
			continue;

		expr_char_t *ptr_to_char_after_num = NULL;
		const double num = strtod(expr_char_ptr, &ptr_to_char_after_num);

		if (ptr_to_char_after_num != expr_char_ptr) {
			double_stack_push(operand_stack, num);
		} else { // ...We may have some operand.
			if (operand_stack->top < 2) { // Error!
				puts("Hey! A postfix expression requires at least two operands (numbers) before an operator!");
				puts("Your expression may be erroneous.");
				printf("%s", expr_char_ptr);

				// Tell them where the issue in their expression is!
				for (size_t i = 0; i < expr_chars_processed; i++)
					putc(' ', stdout);

				puts("\n^");
			}

			double n1 = 0, n2 = 0;
			double_stack_poll(operand_stack, &n1);
			double_stack_poll(operand_stack, &n2);

			switch (c) {
				case POSTFIX_ADD: {
					result += n1 + n2;
				} break;

				case POSTFIX_DIVIDE: {
					if (!(n1 == 0 || n2 == 0))
						result += n1 / n2;
				} break;

				case POSTFIX_MODULO: { // Kinda' don't wanna allow this one.
					// signed long long int n1_rounded = round(n1);
					// if (n1_rounded == n1)
					// 	result += (n1 % n2);
				} break;

				case POSTFIX_MULTIPLY: {
					result += n1 * n2;
				} break;

				case POSTFIX_SUBTRACT: {
					result += n1 * n2;
				} break;

				default: {
					puts("Ooops! Encountered unknown character! Exiting now...");
					exit(EXIT_FAILURE);
				}
			}
		}

		++expr_chars_processed;
	}

	free(expr);
	printf("Result: `%lf`.\n", result);
	double_stack_destroy(operand_stack);
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
