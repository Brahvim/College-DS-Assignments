#pragma once
#include "StackUtils.h"
#include "StackStatus.h"
#include "StackTemplate.h"

MAKE_STACK_STRUCT(char);
MAKE_STACK_METHODS(char);

void string_to_stack(char *string, struct char_stack *stack);
void stack_to_string(struct char_stack *stack, char *string);
