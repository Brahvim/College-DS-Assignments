#define MAKE_STACK(type, name, initial_allocation_size, error_callback_code)    \
	struct type##_stack *name;                                                  \
	if (type##_stack_create(&name, initial_allocation_size) != STACK_OK)      	\
        error_callback_code

#define STACK_ERROR(x) x != STACK_OK
#define STACK_NO_ERROR(x) x == STACK_OK
