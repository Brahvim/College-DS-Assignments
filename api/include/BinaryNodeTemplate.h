#pragma once

#include <stdlib.h>
#include <memory.h>

#define DECLARE_BINARY_NODE_STRUCT(type)			\
struct binary_##type##_node {					\
														\
	type data;											\
	struct binary_##type##_node *next;			\
														\
};														\

#define DECLARE_BINARY_NODE_METHODS(type)																						\
enum binary_node_status create_binary_##type##_node(struct binary_##type##_node **node);							\
																																		\
enum binary_node_status destroy_binary__##type##_list(struct binary_##type##_node *first_node);						\
																																		\
enum binary_node_status destroy_binary_##type##_node(																		\
	struct binary_##type##_node *previous, 																						\
	struct binary_##type##_node *to_destroy);																					\

#define DEFINE_BINARY_NODE_METHODS(type)																								\
enum binary_node_status create_binary_##type##_node(struct binary_##type##_node **p_node) {							\
	*p_node = malloc(sizeof(struct binary_##type##_node));																			\
	struct binary_##type##_node *const node = *p_node;																				\
																																			\
	if (!node)																																\
		return BINARY_NODE_STATUS_MALLOC;																											\
																																			\
	memset(&(node->data), 0, sizeof(type)); /* NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling) */				\
	node->next = NULL;																														\
																																			\
	return BINARY_NODE_STATUS_NO_ERROR;																											\
}																																			\
																																			\
enum binary_node_status destroy_binary__##type##_list(struct binary_##type##_node *p_first_node) {						\
	if (!p_first_node)																														\
		return BINARY_NODE_STATUS_NULL;																											\
																																			\
	struct binary_##type##_node *current = p_first_node;																				\
																																			\
	while (current) {																														\
		struct binary_##type##_node *const next = current->next;																		\
		free(current);																														\
		current = next;																														\
	}																																		\
																																			\
	return BINARY_NODE_STATUS_NO_ERROR;																											\
}																																			\
																																			\
enum binary_node_status destroy_binary_##type##_node(																			\
	struct binary_##type##_node *p_previous, struct binary_##type##_node *p_to_free) {										\
	/* ...It's an assignment requirement to use singly-linked nodes, LOL:*/																	\
	if (p_previous && p_to_free)																											\
		p_previous->next = p_to_free->next;																									\
	else return BINARY_NODE_STATUS_NULL;																											\
																																			\
	free(p_to_free);																														\
	return BINARY_NODE_STATUS_NULL;																												\
}																																			\
																																			\

