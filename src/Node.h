#pragma once
#ifndef NODE_H
#define NODE_H

#include <stdint.h>

typedef struct Node_ Node;

struct Node_ 
{
    Node*       leftChild;
    Node*       rightChild;
    uint8_t     symbol;
    uint64_t    frequency;
};


/* Functions */
Node*   node_create(uint8_t symbol, uint64_t frequency);
Node*   node_join(Node* left, Node* right);
void    node_delete(Node **node);
void    node_print(Node *node);

/* Test Functions */
int returnOne();

#endif // NODE_H