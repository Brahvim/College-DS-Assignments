#pragma once

#include <stdlib.h>
#include <memory.h>

// I would've used opaque pointers for this, but...
#define DECLARE_BINARY_NODE_STRUCT(type)			\
struct binary_##type##_node;						\

#define DEFINE_BINARY_NODE_STRUCT(type)				\
struct binary_##type##_node {						\
													\
	type data;										\
	struct binary_##type##_node *left;				\
	struct binary_##type##_node *right;				\
													\
};													\
													\

#define DECLARE_BINARY_NODE_METHODS(type)																\
enum binary_node_status create_binary_##type##_node(struct binary_##type##_node **node);				\
																										\
enum binary_node_status destroy_binary_##type##_tree(struct binary_##type##_node *first_node);			\
																										\
struct binary_##type##_node* get_binary_tree_left_##type##_node(struct binary_##type##_node *node);		\
																										\
struct binary_##type##_node* get_binary_tree_right_##type##_node(struct binary_##type##_node *node);	\
																										\

#define DEFINE_BINARY_NODE_METHODS(type)																								\
enum binary_node_status create_binary_##type##_node(struct binary_##type##_node **p_node) {												\
	*p_node = malloc(sizeof(struct binary_##type##_node));																				\
	struct binary_##type##_node *const node = *p_node;																					\
																																		\
	if (!node)																															\
		return BINARY_NODE_STATUS_MALLOC;																								\
																																		\
	node->left = NULL;																													\
	node->right = NULL;																													\
	memset(&(node->data), 0, sizeof(type)); /* NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) */			\
																																		\
	return BINARY_NODE_STATUS_NO_ERROR;																									\
}																																		\
																																		\
/* This will require post-order traversal.*/																							\
enum binary_node_status destroy_binary_##type##_tree(struct binary_##type##_node *p_first_node) { 										\
	return BINARY_NODE_STATUS_MALLOC;																									\
}																																		\
																																		\
inline struct binary_##type##_node* get_binary_tree_left_##type##_node(struct binary_##type##_node *p_node) {							\
	return p_node->left;																												\
}																																		\
																																		\
inline struct binary_##type##_node* get_binary_tree_right_##type##_node(struct binary_##type##_node *p_node) {							\
	return p_node->right;																												\
}																																		\
																																		\

