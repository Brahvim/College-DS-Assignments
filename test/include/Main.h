#pragma once

#include "Stack.h"
#include "ReadLine.h"

typedef enum {
    POSTFIX_OPERATION_ADD = '+',
    POSTFIX_OPERATION_DIVIDE = '/',
    // POSTFIX_OPERATION_MODULO = '%',
    POSTFIX_OPERATION_MULTIPLY = '*',
    POSTFIX_OPERATION_SUBTRACT = '-',
} postfix_evaluator_operation;

const int g_postfix_evaluator_operations[4] = {
    POSTFIX_OPERATION_ADD,
    POSTFIX_OPERATION_DIVIDE,
    POSTFIX_OPERATION_MULTIPLY,
    POSTFIX_OPERATION_SUBTRACT,
};

typedef enum {
    POSTFIX_ERROR_A,
} postfix_evaluator_error;

const int g_postfix_evaluator_errors[4] = {
    POSTFIX_ERROR_A,
};

MAKE_STACK_OF(double);
typedef char expr_char_t;

// Program-specific stuff:
double postfix_evaluator_evaluate(expr_char_t *expr);
void postfix_evaluator_report_error(const size_t error_char_id, const char *error_message);
