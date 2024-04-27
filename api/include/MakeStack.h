#ifndef TYPE
#error "Please define `TYPE` as the data-type you want to use to make stacks."
#else
#include <stddef.h>

struct TYPE##_stack {

    size_t top;
    TYPE *array;

};


TYPE##_stack* pop_##TYPE##_stack(const TYPE##_stack *stack) {
    (*stack->top)--;
}

TYPE##_stack* destroy_##TYPE##_stack(const TYPE##_stack *stack) {

}

TYPE##_stack* create_##TYPE##_stack(const size_t initial_allocation_size) {

}

TYPE##_stack* push_##TYPE##_stack(const TYPE##_stack *stack, const TYPE element) {

}

#endif
