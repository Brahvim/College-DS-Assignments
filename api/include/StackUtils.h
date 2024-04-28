#define STACK_ERROR(x) (x != STACK_OK)
#define STACK_NO_ERROR(x) (x == STACK_OK)

#define MAKE_STACK(type, name, initial_allocation_size, error_code_block)    \
	struct type##_stack *name;                                                  \
	if (STACK_ERROR(type##_stack_create(&name, initial_allocation_size)))    	\
        error_code_block
