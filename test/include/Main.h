#pragma once
#include "Stack.h"

typedef enum {
    POSTFIX_ADD = '+',
    POSTFIX_DIVIDE = '/',
    POSTFIX_MODULO = '%',
    POSTFIX_MULTIPLY = '*',
    POSTFIX_SUBTRACT = '-',
} postfix_operation;

MAKE_STACK_OF(char);
