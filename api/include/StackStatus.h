#pragma once

/** @brief These are error codes that stack API functions can return. */
typedef enum {
	STACK_OK, /** No error! */
	STACK_MALLOC, /** `malloc()` returned `NULL` trying to allocate for the stack (and not the array backing it). */
	STACK_OVERFLOW, /** The stack encountered an overflow!... */
	STACK_UNDERFLOW, /** The stack underflowed. */
	STACK_BACK_MALLOC, /** There was a failure in allocating the backing array for a stack using `calloc()`. */
	STACK_ERROR_ENUMS_COUNT /** ...This is how many error codes any function for stacks can return. */
} stack_status;
