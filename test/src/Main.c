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
		printf("%zu. `%c`.\n", i, g_postfix_evaluator_operations[i]);

	puts("Please enter your postfix expression below:");

	size_t expr_len = 0;
	expr_char_t *expr = read_line(5, &expr_len);
	++expr_len;

	// double result = 0;
	// switch (false) {
	// 	case true: {
	//
	// 	} break;
	//
	// 	case false: {
	//
	// 	} break;
	//
	// 	default: {
	//
	// 	} break;
	// }

	postfix_evaluator_evaluate(expr);
	free(expr);
}

#pragma region // Program-specific stuff.
double postfix_evaluator_evaluate(expr_char_t *p_expr) {
	MAKE_STACK_HANDLING_ALL(double, operand_stack, 0, {
		puts("Failed to allocate for `operand_stack`...\n");
		exit(EXIT_FAILURE);
	});

	expr_char_t c = 0;
	size_t expr_chars_processed = 0;

	for (expr_char_t *expr_char_ptr = p_expr; (c = *expr_char_ptr) != '\0'; expr_char_ptr += sizeof(expr_char_t)) {
		// Absolutely ignore whitespaces:
		if (c == ' ' || c == '\t')
			continue;

		expr_char_t *ptr_to_char_after_num = NULL;
		const double num = strtod(expr_char_ptr, &ptr_to_char_after_num);

		if (ptr_to_char_after_num != expr_char_ptr) {
			double_stack_push(operand_stack, num);
		} else { // ...We may have some operand.
			if (operand_stack->top < 2)  // Error!
				postfix_evaluator_report_error(expr_chars_processed + 2, "(Two operands required for an operation.)");

			double result = 0;
			double n1 = 0, n2 = 0;
			double_stack_poll(operand_stack, &n1);
			double_stack_poll(operand_stack, &n2);

			switch (c) {
				case POSTFIX_OPERATION_ADD: {
					result = n1 + n2;
				} break;

				case POSTFIX_OPERATION_DIVIDE: {
					if (n1 == 0 || n2 == 0)
						postfix_evaluator_report_error(expr_chars_processed + 2, "Division by zero!");

					result = n1 / n2;
				} break;

											 //    case POSTFIX_MODULO: { // Kinda' don't wanna allow this one.
											 // 		signed long long int n1_rounded = round(n1);
											 // 		if (n1_rounded == n1)
											 // 			result = (n1 % n2);
											 //    } break;

				case POSTFIX_OPERATION_MULTIPLY: {
					result = n1 * n2;
				} break;

				case POSTFIX_OPERATION_SUBTRACT: {
					result = n2 - n1;
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

	double to_ret = 0;
	double_stack_poll(operand_stack, &to_ret);
	double_stack_destroy(operand_stack);
	return to_ret;
}

void postfix_evaluator_report_error(const size_t p_error_char_id, const char *p_error_message) {
	// printf("%s\n", expr);

	// Where is the issue in the expression...?:
	for (size_t i = 0; i < p_error_char_id; i++)
		putc(' ', stdout);

	puts("^"); // Better than two `putc()` calls!
	puts(p_error_message);
	puts("Please retry.");
	exit(EXIT_FAILURE);
}
#pragma endregion
