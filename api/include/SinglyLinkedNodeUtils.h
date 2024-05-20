#pragma once

#define SINGLY_LINKED_NODE_OKAY(x) ((x) == SINGLY_LINKED_NODE_STATUS_NO_ERROR)

#define SINGLY_LINKED_NODE_ERROR(x) ((x) != SINGLY_LINKED_NODE_STATUS_NO_ERROR)

#define MAKE_SINGLY_LINKED_NODE_HANDLING_ALL(type, name, error_name, error_code_block)		\
struct singly_linked_##type##_node *name;                      								\
enum singly_linked_node_status error_name;                      							\
																							\
if (SINGLY_LINKED_NODE_ERROR(error_name = create_singly_linked_##type##_node(&name)))		\
	error_code_block																		\
																							\

#define MAKE_SINGLY_LINKED_NODE_HANDLING_EACH(type, name, error_name, malloc_code_block, null_code_block)		\
struct singly_linked_##type##_node *name;                      													\
																												\
switch (create_singly_linked_##type##_node(&name)) {															\
	case SINGLY_LINKED_NODE_STATUS_NULL: malloc_code_block break;																\
																												\
	case SINGLY_LINKED_NODE_STATUS_MALLOC: null_code_block break;																\
																												\
	default:																									\
	break;																										\
}																												\
																												\

#define TRAVERSE_SINGLY_LINKED_LIST(type, list, iterable_name, loop_body)																		\
	if (list != NULL)																															\
		for (struct singly_linked_##type##_node *iterable_name = list; iterable_name != NULL; iterable_name = iterable_name->next) loop_body	\
																																				\

