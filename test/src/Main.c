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

	struct postfix_evaluator_status_data *status = postfix_evaluator_evaluate(expr);
	if (status->error_enum != POSTFIX_ERROR_NONE) {
		report_postfix_evaluator_error(status);
		exit(EXIT_FAILURE);
	}

	printf("%lf\n", status->result);

	free(expr);
	free(status);
	exit(EXIT_SUCCESS);
}

void report_postfix_evaluator_error(const struct postfix_evaluator_status_data *p_error_data) {
	if (p_error_data->error_enum == POSTFIX_ERROR_NONE)
		return;

	// Where is the issue in the expression...?:
	for (size_t i = 0; i < p_error_data->error_char_index; i++)
		putc(' ', stdout);

	puts("^"); // Better than two `putc()` calls!
	puts(postfix_evaluator_error_to_string(p_error_data->error_enum));
	puts("Please retry.");
}
