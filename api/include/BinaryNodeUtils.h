#pragma once

#define BINARY_NODE_OKAY(x) ((x) == BINARY_NODE_STATUS_NO_ERROR)

#define BINARY_NODE_ERROR(x) ((x) != BINARY_NODE_STATUS_NO_ERROR)

#define MAKE_BINARY_NODE_HANDLING_ALL(type, name, error_name, error_code_block)			\
struct binary_##type##_node *name;                      								\
enum binary_node_status error_name;                      								\
																						\
if (BINARY_NODE_ERROR(error_name = create_binary_##type##_node(&name)))					\
	error_code_block																	\
																						\

#define MAKE_NODE_HANDLING_EACH(type, name, error_name, malloc_code_block, null_code_block)			\
struct binary_##type##_node *name;                      											\
																									\
switch (create_binary_##type##_node(&name)) {														\
	case BINARY_NODE_STATUS_NULL: malloc_code_block break;											\
																									\
	case BINARY_NODE_STATUS_MALLOC: null_code_block break;											\
																									\
	default:																						\
	break;																							\
}																									\
																									\

#define TRAVERSE_LINKED_LIST(type, list, iterable_name, loop_body)																				\
	if (list != NULL)																															\
		for (struct binary_##type##_node *iterable_name = list; iterable_name != NULL; iterable_name = iterable_name->next) loop_body			\
																																				\
																																				\

