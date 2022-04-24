#include "Node.h"

/*
 * Function that allocates memory and creates a node 
 * given a symbol and frequncy (ie. Constructor)
 */
Node* node_create(uint8_t symbol, uint64_t frequency)
{
    // Initialize
    Node* node = NULL;

    // Allocate memory
    node = malloc(sizeof(Node));

    // Error check
    if (node == NULL)
    {
        return NULL;
    }
    // Assign data values
    node->symbol = symbol;
    node->frequency = frequency;

    return node;
}

/*
 * Function that acts as a destructor for node by 
 * deallocating memory and sets the pointer to NULL
 */
 Node* node_delete(Node** node)
 {
     
 }