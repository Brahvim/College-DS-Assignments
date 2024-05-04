#pragma once
#include <stdlib.h>
#include <stdbool.h>

#define MAKE_STACK_OF(type)		\
MAKE_STACK_STRUCT(type);		\
MAKE_STACK_METHODS(type)

#define MAKE_STACK_STRUCT(type)     \
struct type##_stack {               \
                                    \
    type *array;                    \
    size_t top;                     \
    size_t fits;               		\
                                    \
}

#define MAKE_STACK_METHODS(type)                                                                    	\
void type##_stack_destroy(struct type##_stack *stack) {                                             	\
		if (stack != NULL)                                                                          	\
	        free(stack);                                                                            	\
}                                                                                                   	\
																										\
bool type##_stack_is_empty(struct type##_stack *stack) {												\
	return stack->top < 1;																				\
}																										\
																										\
stack_status type##_stack_pop(struct type##_stack *stack) {                                         	\
    if (type##_stack_is_empty(stack))                                                                   \
        return STACK_EMPTY;                                                                     		\
                                                                                                    	\
    --(stack->top);                                                                                 	\
    return STACK_OK;                                                                                	\
}																										\
                                                                                                    	\
stack_status type##_stack_peek(struct type##_stack *stack, type *out) {                                 \
	if (type##_stack_is_empty(stack)) 																	\
		return STACK_EMPTY;																				\
                                                                                                   		\
    *out = stack->array[stack->top];																	\
	return STACK_OK;																					\
}                                                                                                   	\
                                                                                                    	\
stack_status type##_stack_poll(struct type##_stack *stack, type *out) {                                 \
	if (type##_stack_is_empty(stack)) 																	\
		return STACK_EMPTY;																				\
                                                                                                    	\
    --(stack->top);																						\
    *out = stack->array[stack->top];																	\
    return STACK_OK;																					\
}                                                                                                   	\
																										\
stack_status type##_stack_push(struct type##_stack *stack, const type element) {                    	\
	if (stack->top >= stack->fits) {                                                        			\
		const size_t new_size = stack->fits * 2;														\
		type *new_array = realloc(stack->array, new_size * sizeof(type));                				\
																										\
		if (new_array == NULL)                                                                			\
			return STACK_MALLOC;                                                              			\
																										\
		stack->fits = new_size;                                                             			\
		stack->array = new_array;                                                           			\
	}                                                                                            		\
																										\
	stack->array[stack->top++] = element;                                                       		\
	return STACK_OK;   																					\
}                                                                                                   	\
                                                                                                    	\
stack_status type##_stack_create(struct type##_stack **out_stack, size_t initial_allocation_size) {		\
	struct type##_stack *stack = malloc(sizeof(struct type##_stack));                          			\
	if (stack == NULL)																					\
		return STACK_MALLOC;																			\
																										\
	if (initial_allocation_size < 0)																	\
		initial_allocation_size = 1;																	\
																										\
	stack->top = 0;                                                      								\
	stack->fits = initial_allocation_size;                                                      		\
	stack->array = calloc(initial_allocation_size, sizeof(type));                              			\
																										\
	if (stack->array == NULL)																			\
		return STACK_BACK_MALLOC;                                                                       \
																										\
		*out_stack = stack;																				\
																										\
	return STACK_OK;																					\
}
