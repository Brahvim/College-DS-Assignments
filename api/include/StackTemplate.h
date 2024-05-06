#pragma once

#include <stdlib.h>
#include <stdbool.h>

#define DECLARE_STACK_OF(type)	\
DEFINE_STACK_STRUCT(type);		\
DECLARE_STACK_METHODS(type)

#define DEFINE_STACK_OF(type)	\
DEFINE_STACK_METHODS(type)


#define DEFINE_STACK_STRUCT(type)	\
struct type##_stack { 				\
									\
	type *array;                   	\
	size_t top;                     \
	size_t fits;               		\
									\
}

#define DECLARE_STACK_METHODS(type)                                                                    	\
void type##_stack_destroy(struct type##_stack *stack);                                              	\
																										\
bool type##_stack_is_empty(struct type##_stack *stack); 												\
																										\
stack_status type##_stack_pop(struct type##_stack *stack);                                          	\
																										\
stack_status type##_stack_peek(struct type##_stack *stack, type *out);                                  \
																										\
stack_status type##_stack_poll(struct type##_stack *stack, type *out);                                  \
																										\
stack_status type##_stack_push(struct type##_stack *stack, const type element);                     	\
																										\
stack_status type##_stack_create(struct type##_stack **out_stack, size_t initial_allocation_size);		\

#define DEFINE_STACK_METHODS(type)                                                                    		\
void type##_stack_destroy(struct type##_stack *p_stack) {                                             		\
		if (p_stack != NULL)                                                                          		\
	        free(p_stack);                                                                            		\
}                                                                                                   		\
																											\
bool type##_stack_is_empty(struct type##_stack *p_stack) {													\
	return p_stack->top < 1;																				\
}																											\
																											\
stack_status type##_stack_pop(struct type##_stack *p_stack) {                                         		\
    if (type##_stack_is_empty(p_stack))                                                                 	\
        return STACK_EMPTY;                                                                     			\
                                                                                                    		\
    --(p_stack->top);                                                                                 		\
    return STACK_OK;                                                                                		\
}																											\
                                                                                                    		\
stack_status type##_stack_peek(struct type##_stack *p_stack, type *p_out) {                             	\
	if (type##_stack_is_empty(p_stack)) 																	\
		return STACK_EMPTY;																					\
                                                                                                   			\
    *p_out = p_stack->array[p_stack->top];																	\
	return STACK_OK;																						\
}                                                                                                   		\
                                                                                                    		\
stack_status type##_stack_poll(struct type##_stack *p_stack, type *p_out) {                             	\
	if (type##_stack_is_empty(p_stack)) 																	\
		return STACK_EMPTY;																					\
                                                                                                    		\
    --(p_stack->top);																						\
    *p_out = p_stack->array[p_stack->top];																	\
    return STACK_OK;																						\
}                                                                                                   		\
																											\
stack_status type##_stack_push(struct type##_stack *p_stack, const type p_element) {                    	\
	if (p_stack->top >= p_stack->fits) {                                                        			\
		const size_t new_size = p_stack->fits * 2;															\
		type *new_array = realloc(p_stack->array, new_size * sizeof(type));                					\
																											\
		if (new_array == NULL)                                                                				\
			return STACK_MALLOC;                                                              				\
																											\
		p_stack->fits = new_size;                                                             				\
		p_stack->array = new_array;                                                           				\
	}                                                                                            			\
																											\
	p_stack->array[p_stack->top++] = p_element;                                                       		\
	return STACK_OK;   																						\
}                                                                                                   		\
                                                                                                    		\
stack_status type##_stack_create(struct type##_stack **p_out_stack, size_t p_initial_allocation_size) {		\
	struct type##_stack *stack = malloc(sizeof(struct type##_stack));  ;                        			\
	if (stack == NULL)																						\
		return STACK_MALLOC;																				\
																											\
	if (p_initial_allocation_size < 1)																		\
		p_initial_allocation_size = 1;																		\
																											\
	stack->top = 0;                                                      									\
	stack->fits = p_initial_allocation_size;                                                      			\
	stack->array = calloc(p_initial_allocation_size, sizeof(type));                              			\
																											\
	if (stack->array == NULL)																				\
		return STACK_BACK_MALLOC;                                                                       	\
																											\
		*p_out_stack = stack;																				\
																											\
	return STACK_OK;																						\
}																											\

