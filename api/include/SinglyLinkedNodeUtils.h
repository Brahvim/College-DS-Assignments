#pragma once

#define NODE_OKAY(x) ((x) == NODE_STATUS_NO_ERROR)

#define NODE_ERROR(x) ((x) != NODE_STATUS_NO_ERROR)

#define MAKE_NODE_HANDLING_ALL(type, name, error_name, error_code_block)	\
struct singly_linked_##type##_node *name;                      				\
enum singly_linked_node_status error_name;                      			\
																			\
if (NODE_ERROR(error_name = create_singly_linked_##type##_node(&name)))     \
	error_code_block														\

#define MAKE_NODE_HANDLING_EACH(type, name, error_name, malloc_code_block, null_code_block)		\
struct singly_linked_##type##_node *name;                      									\
																								\
switch (create_singly_linked_##type##_node(&name)) {											\
	case NODE_STATUS_NULL:																		\
		malloc_code_block																		\
	break;																						\
																								\
	case NODE_STATUS_MALLOC:																	\
		null_code_block																			\
	break;																						\
																								\
	default:																					\
	break;																						\
}																								\

#define MAKE_LINKED_LIST_HANDLING_ALL(type, name, error_name, length, error_code_block)							\
																												\
	struct singly_linked_##type##_node *name = NULL;															\
	size_t name##_length = length;																				\
	struct singly_linked_##type##_node *name_##_last_node = NULL;												\
																												\
	for (size_t name##_allocated_length = 0; name##_allocated_length < length; ++name##_allocated_length) {		\
		enum singly_linked_node_status error_name;																\
																												\
		if (NODE_ERROR(error_name = create_singly_linked_##type##_node(&name))) 								\
			error_code_block;																					\
	}																											\

