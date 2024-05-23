#include "PostfixEvaluator.h"

DEFINE_STACK_OF(double);

struct postfix_evaluator_status_data* postfix_evaluator_evaluate(expr_char_t *p_expr) {
	// Nobody needs a collection for this, haha!:
	MAKE_STACK_HANDLING_ALL(double, operand_stack, 2, {
		puts("Failed to allocate for `operand_stack`...\n");
		exit(EXIT_FAILURE);
	});

	expr_char_t c = 0;
	size_t expr_chars_processed = 0;
	struct postfix_evaluator_status_data *to_ret = malloc(sizeof(struct postfix_evaluator_status_data));

	for (expr_char_t *expr_char_ptr = p_expr; (c = *expr_char_ptr) != '\0'; expr_char_ptr += sizeof(expr_char_t)) {
		// Absolutely ignore whitespaces:
		if (c == ' ' || c == '\t')
			continue;

		expr_char_t *ptr_to_char_after_num = NULL;
		const double num = strtod(expr_char_ptr, &ptr_to_char_after_num);

		if (ptr_to_char_after_num != expr_char_ptr) {
			double_stack_push(operand_stack, num);
			expr_char_ptr = ptr_to_char_after_num;
		} else { // ...We may have some operand.
			if (operand_stack->top < 2) { // Error!
				to_ret->error_enum = POSTFIX_ERROR_INSUFFICIENT_OPERANDS;
				to_ret->error_char_index = expr_chars_processed + 1;
				goto error_cleanup;
			}

			double result = 0;
			double n1 = 0, n2 = 0;
			double_stack_poll(operand_stack, &n1);
			double_stack_poll(operand_stack, &n2);

			switch (c) {
				case POSTFIX_OPERATION_ADD: {
					result = n1 + n2;
				} break;

				case POSTFIX_OPERATION_DIVIDE: {
					if (n1 == 0 || n2 == 0) {
						to_ret->error_char_index = expr_chars_processed + 2;
						to_ret->error_enum = POSTFIX_ERROR_DIVIDE_BY_ZERO;
						goto error_cleanup;
					}
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

	to_ret->error_enum = POSTFIX_ERROR_NONE;
	double_stack_poll(operand_stack, &to_ret->result);

error_cleanup:
	double_stack_destroy(operand_stack);
	return to_ret;
}

const char* postfix_evaluator_error_to_string(const enum postfix_evaluator_error p_error_enum) {
	switch (p_error_enum) {
		// case POSTFIX_ERROR_NONE:
		// return "No errors. Please ignore this message.";

		case POSTFIX_ERROR_DIVIDE_BY_ZERO:
		return "Division by zero!";

		case POSTFIX_ERROR_INSUFFICIENT_OPERANDS:
		return "An operator must come only after two operands (numbers)!";

		default: return "";
	};
}
