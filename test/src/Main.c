#include "Main.h"

int main() {

    MAKE_NODE_HANDLING_ALL(list, error, {});

    size_t length = 10;

    struct node *name = (struct node*)0x55;
    size_t name__length = 1;

    if (length > 0)
        name__length = length;

    struct node *name__last_node = name;
    struct node *name__current_node = name;

    for (size_t name___allocated_length = 0; name___allocated_length < name__length; ++name___allocated_length) {
        enum node_status error_name;

        if (NODE_ERROR(error_name = create_node(&name__current_node)))
            // error_code_block
            ;

        name__last_node->next = name__current_node;
        name__last_node = name__current_node;
    }


}
