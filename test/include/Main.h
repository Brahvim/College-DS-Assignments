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

void clear_stdin(void);
char* read_line(const size_t factor);
void stack_to_string(struct char_stack *stack, char *string);
void string_to_stack(const char *string, struct char_stack *stack);

