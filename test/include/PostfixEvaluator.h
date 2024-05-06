#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#include "Stack.h"

#pragma region // `enum`s and their arrays.
enum postfix_evaluator_error {

	POSTFIX_ERROR_NONE,

	POSTFIX_ERROR_DIVIDE_BY_ZERO,

	POSTFIX_ERROR_INSUFFICIENT_OPERANDS,

};

enum postfix_evaluator_operation {

	POSTFIX_OPERATION_ADD = '+',

	POSTFIX_OPERATION_DIVIDE = '/',

	// POSTFIX_OPERATION_MODULO = '%',

	POSTFIX_OPERATION_MULTIPLY = '*',

	POSTFIX_OPERATION_SUBTRACT = '-',

};

static const enum postfix_evaluator_error g_postfix_evaluator_errors[] = {
	POSTFIX_ERROR_NONE,
	POSTFIX_ERROR_DIVIDE_BY_ZERO,
	POSTFIX_ERROR_INSUFFICIENT_OPERANDS,
};

static const enum postfix_evaluator_operation g_postfix_evaluator_operations[] = {
	POSTFIX_OPERATION_ADD,
	POSTFIX_OPERATION_DIVIDE,
	POSTFIX_OPERATION_MULTIPLY,
	POSTFIX_OPERATION_SUBTRACT,
};
#pragma endregion

struct postfix_evaluator_status_data {

	/** @brief  The result of the expression's evaluation! */
	double result;

	/** @brief Where in the expression is the error? */
	size_t error_char_index;

	/** @brief What is the error? */
	enum postfix_evaluator_error error_enum;

};

typedef char expr_char_t;

DECLARE_STACK_OF(double);

// Program-specific stuff:
struct postfix_evaluator_status_data* postfix_evaluator_evaluate(expr_char_t *expr);
const char* postfix_evaluator_error_to_string(const enum postfix_evaluator_error error_enum);
