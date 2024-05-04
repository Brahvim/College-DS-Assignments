#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "Main.h"

int main() {
	puts("Welcome to the literals postfix expression evaluator.");
	puts("Supported operators include:");
	for (size_t i = 0; i < 4; i++)
		printf("%zu. `%c`.\n", i, g_postfix_operations[i]);

	puts("Please enter your postfix expression below:");

	size_t expr_len = 0;
	expr_char_t *expr = read_line(5, &expr_len);
	++expr_len;

	MAKE_STACK_HANDLING_ALL(double, operand_stack, 0, {
		puts("Failed to allocate for `operand_stack`...\n");
		exit(EXIT_FAILURE);
	});

	expr_char_t c = 0;
	// double result = 0;
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
				printf("%s\n", expr_char_ptr);

				// Tell them where the issue in their expression is!
				for (size_t i = -1; i < expr_chars_processed; i++)
					putc(' ', stdout);

				puts("^");
				puts("(Erroneous operator).");
				exit(EXIT_FAILURE);
			}

			double result = 0;
			double n1 = 0, n2 = 0;
			double_stack_poll(operand_stack, &n1);
			double_stack_poll(operand_stack, &n2);

			switch (c) {
				case POSTFIX_ADD: {
					result = n1 + n2;
				} break;

				case POSTFIX_DIVIDE: {
					if (n1 == 0 || n2 == 0) {
					}

					result = n1 / n2;
				} break;

								   //    case POSTFIX_MODULO: { // Kinda' don't wanna allow this one.
								   // 		signed long long int n1_rounded = round(n1);
								   // 		if (n1_rounded == n1)
								   // 			result = (n1 % n2);
								   //    } break;

				case POSTFIX_MULTIPLY: {
					result = n1 * n2;
				} break;

				case POSTFIX_SUBTRACT: {
					result = n1 - n2;
				} break;

				default: {
					puts("Ooops! Encountered unknown character! Exiting now...");
					exit(EXIT_FAILURE);
				}
			}

			double_stack_push(operand_stack, result);
		}

		++expr_chars_processed;
	}

	double result;
	double_stack_poll(operand_stack, &result);

	free(expr);
	printf("Result: `%lf`.\n", result);
	double_stack_destroy(operand_stack);
}

#pragma region // Program-specific stuff.
void postfix_evaluator_error(const size_t p_error_char_id, const char *p_error_message) {
	// printf("%s\n", expr);
	// Where is the issue in the expression...?:
	for (size_t i = 0; i < p_error_char_id; i++)
		putc(' ', stdout);

	puts("^"); // Better than two `putc()` calls!
	puts(p_error_message);
	exit(EXIT_FAILURE);
}
#pragma endregion
