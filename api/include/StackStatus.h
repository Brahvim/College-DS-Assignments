#define MAKE_STACK(type, name, initial_allocation_size, error_callback_code)    \
	struct type##_stack *name;                                                  \
	if (type##_stack_create(&name, initial_allocation_size) != STACK_OK)      	\
        error_callback_code

typedef enum {
	STACK_OK,
	STACK_MALLOC,
	STACK_OVERFLOW,
	STACK_UNDERFLOW,
	STACK_ERROR_ENUMS_COUNT
} stack_status;
