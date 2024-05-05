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
