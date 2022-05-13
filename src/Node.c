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
 *
 *
 */
Node* node_join(Node* left, Node* right)
{
    // TODO: Implement (following code is a place holder)
    left = right;
    return left;
}

/*
 *
 *
 */
 void node_print(Node* node)
 {
    // TODO: Implement (following code is a place holder)
    printf("symbol: %d, frequency %ld", node->symbol, node->frequency);
 }

/*
 *
 *
 */
 int returnOne()
 {
    return 1;
 }