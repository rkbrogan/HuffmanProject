#include "Node.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Function that allocates memory and creates a node 
 * given a symbol and frequncy (ie. Constructor)
 */
Node* node_create(uint8_t symbol, uint64_t frequency)
{
    // Initialize
    Node* node = NULL;

    // Allocate memory
    node = (Node*)malloc(sizeof(Node));

    // Error check
    if (node == NULL)
    {
        return NULL;
    }
    // Assign data values
    node->symbol = symbol;
    node->frequency = frequency;

    // Assign left and right to NULL
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

/*
 * Function that acts as a destructor for node by 
 * deallocating memory and sets the pointer to NULL
 */
void node_delete(Node** node)
 {
    free(*node);
    *node = NULL;
 }

/*
 * Function that joins two nodes and sets their symbol to '$' and combines their frequencies
 * and sets those values to a newly created parent node.
 */
Node* node_join(Node* left, Node* right)
{
    // Create parent node to return
    Node* parent = node_create('$', left->frequency + right->frequency);
    
    // Set its children as the parameter nodes
    parent->leftChild = left;
    parent->rightChild = right;

    return parent;
}

/*
 * Function that prints the symbol and frequency of a node (debugging purposes)
 */
 void node_print(Node* node)
 {
    printf("symbol: %d, frequency %ld", node->symbol, node->frequency);
 }
