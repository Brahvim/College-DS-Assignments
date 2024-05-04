#pragma once
#include "Stack.h"

typedef enum {
    POSTFIX_ADD = '+',
    POSTFIX_DIVIDE = '/',
    POSTFIX_MODULO = '%',
    POSTFIX_MULTIPLY = '*',
    POSTFIX_SUBTRACT = '-',
} postfix_operation;

typedef char expr_char_t;

MAKE_STACK_OF(char);
MAKE_STACK_OF(double);
// MAKE_STACK_OF(expr_char_t);

/**
 * [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ],
 * [ https://github.com/Brahvim/College-C-Assignments/blob/26934f9777473ebb2a759f2f17f9715820ffa46f/ReadLine.c#L7 ].
 */
void clear_stdin(void);
// ...I modified this one:
char* read_line(const size_t factor, size_t *out_size);

// From the previous question, <chuckle>!:
void stack_to_string(struct char_stack *stack, char *string);
void string_to_stack(const char *string, struct char_stack *stack);
