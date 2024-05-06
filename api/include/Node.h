#pragma once

#include <stddef.h>

#define NODE_OKAY(x) ((x) == NODE_STATUS_NO_ERROR)

#define NODE_ERROR(x) ((x) != NODE_STATUS_NO_ERROR)

#define MAKE_NODE_HANDLING_ALL(name, error_name, error_code_block)		\
struct node *name;                      								\
enum node_status error_name;                      						\
																		\
if (NODE_ERROR(error_name = create_node(&name)))     					\
	error_code_block													\

#define MAKE_NODE_HANDLING_EACH(name, error_name, malloc_code_block, null_code_block)		\
struct node *name;                      													\
																							\
switch (create_node(&name)) {																\
	case NODE_STATUS_NULL:																	\
		malloc_code_block																	\
	break;																					\
																							\
	case NODE_STATUS_MALLOC:																\
		null_code_block																		\
	break;																					\
																							\
	default:																				\
	break;																					\
}																							\

#define MAKE_LINKED_LIST_HANDLING_ALL(name, error_name, length, error_code_block)								\
																												\
	struct node *name = NULL;																					\
	size_t name##_length = length;																				\
	struct node *name_##_last_node = NULL;																		\
																												\
	for (size_t name##_allocated_length = 0; name##_allocated_length < length; ++name##_allocated_length) {		\
		enum node_status error_name;																			\
																												\
		if (NODE_ERROR(error_name = create_node(&name))) 														\
			error_code_block;																					\
	}																											\


struct node {

	int *data;
	struct node *next;

};

enum node_status {

	NODE_STATUS_NULL,

	NODE_STATUS_MALLOC,

	NODE_STATUS_NO_ERROR,

};

enum node_status create_node(struct node **node);

enum node_status destroy_node(struct node *node);

enum node_status destroy_linked_list(struct node *first_node);

enum node_status insert_node_in_linked_list(struct node *node);

enum node_status create_linked_list(struct node **memory, size_t list_length);
