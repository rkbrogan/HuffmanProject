#include "PriorityQueue.h"

#include <assert.h>
#include <stdlib.h>

PriorityQueue* pq_create(uint32_t capacity)
{
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    assert(pq != NULL);

    pq->capacity = capacity;
    pq->size = 0;

    Node* node = node_create(0, 0);
    pq->nodes = malloc(sizeof(Node*) * capacity);
    assert(pq->nodes != NULL);

    // TODO: Initialize the array of nodes

}

void pq_delete(PriorityQueue** pq)
{
    assert(pq);
    *pq = NULL;
}

void pq_print(PriorityQueue *pq)
{
    assert(pq);

    for(uint32_t i = 0; i < pq->capacity; i++)
    {
        if(pq->nodes[i] != NULL)
        {
            node_print(pq->nodes[i]);
        }
    }
}


bool pq_empty(PriorityQueue* pq)
{
    return pq->size == 0;
}

bool pq_full(PriorityQueue* pq)
{
    return pq->size == pq->capacity;
}


bool enqueue(PriorityQueue* pq, Node* n)
{
    assert(pq);

    if (pq_full(pq))
    {
        return false;
    }

    // TODO: Finish implementing this function
}

// bool dequeue(PriorityQueue* pq, Node **n)
// {

// }

uint32_t pq_size(PriorityQueue *pq)
{
    return pq->size;
}