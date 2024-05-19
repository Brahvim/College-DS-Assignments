#pragma once

#include <stdlib.h>

#define DECLARE_SINGLY_LINKED_NODE_STRUCT(type)			\
struct singly_linked_##type##_node {					\
														\
	type data;											\
	struct singly_linked_##type##_node *next;			\
														\
};														\

#define DECLARE_SINGLY_LINKED_NODE_METHODS(type)																						\
enum singly_linked_node_status create_singly_linked_##type##_node(struct singly_linked_##type##_node **node);							\
																																		\
enum singly_linked_node_status destroy_singly_linked_##type##_list(struct singly_linked_##type##_node *first_node);						\
																																		\
enum singly_linked_node_status destroy_singly_linked_##type##_node(																		\
	struct singly_linked_##type##_node *previous, 																						\
	struct singly_linked_##type##_node *to_destroy);																					\

#define DEFINE_SINGLY_LINKED_NODE_METHODS(type)																								\
																																			\
enum singly_linked_node_status create_singly_linked_##type##_node(struct singly_linked_##type##_node **p_node) {								\
	*p_node = malloc(sizeof(struct singly_linked_##type##_node));																			\
																																			\
	if (!(*p_node))																															\
	return NODE_STATUS_MALLOC;																												\
																																			\
	(*p_node)->data = 0;																													\
	(*p_node)->next = NULL;																													\
																																			\
	return NODE_STATUS_NO_ERROR;																											\
}																																			\
																																			\
enum singly_linked_node_status destroy_singly_linked_##type##_list(struct singly_linked_##type##_node *p_first_node) {						\
	if (!p_first_node)																														\
		return NODE_STATUS_NULL;																											\
																																			\
	struct singly_linked_##type##_node *current = p_first_node;																				\
																																			\
	while (current) {																														\
		struct singly_linked_##type##_node *next = current->next;																			\
		free(current);																														\
		current = next;																														\
	}																																		\
																																			\
	return NODE_STATUS_NO_ERROR;																											\
}																																			\
																																			\
enum singly_linked_node_status destroy_singly_linked_##type##_node(																			\
	struct singly_linked_##type##_node *p_previous, struct singly_linked_##type##_node *p_to_free) {										\
	/* ...It's an assignment requirement to use singly-linked nodes, LOL:*/																	\
	if (p_previous && p_to_free)																											\
		p_previous->next = p_to_free->next;																									\
	else return NODE_STATUS_NULL;																											\
																																			\
	free(p_to_free);																														\
	return NODE_STATUS_NULL;																												\
}																																			\
																																			\

