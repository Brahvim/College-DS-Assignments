#pragma once

struct node {

    int *data;
    struct node *next;

};

enum node_status {

    NODE_OK,

    NODE_NULL,

    NODE_MALLOC,

};

enum node_status create_node();
