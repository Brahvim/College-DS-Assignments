#include <stdlib.h>
#include <stdbool.h>

#define MAKE_STACK_OF(type)	\
MAKE_STACK_STRUCT(type);	\
MAKE_STACK_METHODS(type)

#define MAKE_STACK_STRUCT(type)     \
struct type##_stack {               \
                                    \
    type *array;                    \
    size_t top;                     \
    size_t fits;               		\
                                    \
}

#define MAKE_STACK_METHODS(type)                                                                    \
bool type##_stack_pop(struct type##_stack *stack) {                                                 \
    if (stack->top < 1)                                                                             \
        return false;                                                                               \
                                                                                                    \
    (stack->top)--;                                                                                 \
    return true;                                                                                    \
}                                                                                                   \
                                                                                                    \
void type##_stack_destroy(struct type##_stack *stack) {                                             \
		if (stack != NULL)                                                                          \
	        free(stack);                                                                            \
}                                                                                                   \
                                                                                                    \
bool type##_stack_push(struct type##_stack *stack, const type element) {                            \
        if (stack->top >= stack->fits) {                                                        	\
			const size_t new_size = stack->fits * 2;												\
			type *new_array = realloc(stack->array, new_size * sizeof(type));                		\
            																						\
			if (new_array == NULL)                                                                	\
                return false;                                                              			\
																									\
			stack->fits = new_size;                                                             	\
			stack->array = new_array;                                                           	\
        }                                                                                           \
                                                                                                    \
        stack->array[stack->top++] = element;                                                       \
        return true;   																				\
}                                                                                                   \
                                                                                                    \
struct type##_stack* type##_stack_create(size_t initial_allocation_size) {                      	\
	struct type##_stack *to_ret = malloc(sizeof(struct type##_stack));                          	\
	if (to_ret == NULL)																				\
		return NULL;																				\
																									\
	to_ret->fits = initial_allocation_size;                                                      	\
	to_ret->array = calloc(initial_allocation_size, sizeof(type));                              	\
																									\
	if (to_ret->array == NULL)																		\
		return NULL;                                                                              	\
																									\
	return to_ret;																					\
}
