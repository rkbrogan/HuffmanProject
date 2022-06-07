#include "PriorityQueue.h"

#include <assert.h>

PriorityQueue* pq_create(uint32_t capacity)
{
    return NULL;
}

void pq_delete(PriorityQueue** pq)
{
    assert(pq);
    *pq = NULL;
}

// void pq_print(PriorityQueue *pq)
// {

// }

bool pq_empty(PriorityQueue* pq)
{
    return pq->size == 0;
}

bool pq_full(PriorityQueue* pq)
{
    return pq->size == pq->capacity;
}

// bool enqueue(PriorityQueue* pq, Node* n)
// {

// }

// bool dequeue(PriorityQueue* pq, Node **n)
// {

// }

// uint32_t pq_size(PriorityQueue *pq)
// {
//     return pq->size;
// }