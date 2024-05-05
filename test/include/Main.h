#pragma once

#include "Stack.h"

DECLARE_STACK_OF(char);

/**
 * [ https://stackoverflow.com/questions/52984551/using-fgets-with-realloc ],
 * [ https://github.com/Brahvim/College-C-Assignments/blob/26934f9777473ebb2a759f2f17f9715820ffa46f/ReadLine.c#L7 ].
 */
void clear_stdin();
char* read_line(const size_t factor, size_t *out_size);
void stack_to_string(struct char_stack *stack, char *string);
void string_to_stack(const char *string, struct char_stack *stack);
