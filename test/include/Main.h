#pragma once

#include "Stack.h"
#include "ReadLine.h"

typedef enum {
    POSTFIX_ADD = '+',
    POSTFIX_DIVIDE = '/',
    // POSTFIX_MODULO = '%',
    POSTFIX_MULTIPLY = '*',
    POSTFIX_SUBTRACT = '-',
} postfix_operation;

const int g_postfix_operations[4] = {
    POSTFIX_ADD,
    POSTFIX_DIVIDE,
    POSTFIX_MULTIPLY,
    POSTFIX_SUBTRACT,
};

MAKE_STACK_OF(double);
typedef char expr_char_t;

// Program-specific stuff:
void postfix_evaluator_error(const size_t p_error_char_id, const char *p_error_message);
