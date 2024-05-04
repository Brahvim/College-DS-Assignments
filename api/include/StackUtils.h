#define STACK_ERROR(x) ((x) != STACK_OK)
#define STACK_NO_ERROR(x) ((x) == STACK_OK)

#define MAKE_STACK_HANDLING_ALL(type, name, initial_allocation_size, error_code_block)									\
	MAKE_STACK_HANDLING_EACH(type, name, initial_allocation_size, error_code_block, error_code_block)

#define MAKE_STACK_HANDLING_EACH(type, name, initial_allocation_size, malloc_code_block, back_malloc_code_block)		\
	struct type##_stack *name = NULL;                                       											\
	switch ((type##_stack_create(&name, initial_allocation_size))) {													\
																														\
		case STACK_MALLOC:																								\
			malloc_code_block																							\
		break;																											\
																														\
		case STACK_BACK_MALLOC: 																						\
			free(name);																									\
			back_malloc_code_block																						\
		break;																											\
																														\
		default:																										\
		break;																											\
																														\
	}
