#pragma once

#define NODE_OKAY(x) ((x) == NODE_OK)

#define NODE_ERROR(x) ((x) != NODE_OK)

struct node {

    int *data;
    struct node *next;

};

enum node_status {

    NODE_NULL,

    NODE_MALLOC,

    NODE_NO_ERROR,

};

enum node_status create_node();

enum node_status insert_node(struct node*);

enum node_status destroy_node(struct node*);

enum node_status put_node_data(struct node*, int data);
