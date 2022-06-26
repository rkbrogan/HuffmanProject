#include "PriorityQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

PriorityQueue* pq_create(uint32_t capacity)
{
    PriorityQueue* pq = malloc(sizeof(PriorityQueue));
    assert(pq != NULL);

    pq->capacity = capacity;
    pq->size = 0;
    pq->head = NULL;

    return pq;
}

void pq_delete(PriorityQueue** pq)
{
    assert(pq);
    *pq = NULL;
}

void pq_print(PriorityQueue *pq)
{
    assert(pq);

    // Walk through queue and print each node's character.
    Node* current = pq->head;
    while (current != NULL)
    {
        printf("%c ", current->symbol);
        current = current->rightChild;
    }
}


bool pq_isEmpty(PriorityQueue* pq)
{
    return pq->size == 0;
}


bool pq_isFull(PriorityQueue* pq)
{
    return pq->size == pq->capacity;
}

// TODO: Fix this function. It is currently a doubly linked list
bool pq_enqueue(PriorityQueue* pq, Node* n)
{
    assert(pq);

    bool result = false;

    if (!pq_isFull(pq))
    {
        // Loop through queue until we find a node with a higher frequency.
        Node* current = pq->head;
        Node* previous = NULL;
    
        while (current != NULL && current->frequency < n->frequency)
        {
            previous = current;
            current = current->rightChild;
        }

        // If we found a node with a higher frequency, insert the new node before it.
        if (current != NULL)
        {
            n->leftChild = current->leftChild;
            n->rightChild = current;
            current->leftChild = n;
        }
        else    // Insert new node at the end
        {
            n->leftChild = NULL;
            n->rightChild = NULL;

            if (previous != NULL)
            {
                previous->rightChild = n;
            }
        }

        // If the head is NULL, the new node is the head.
        if (pq->head == NULL)
        {
            pq->head = n;
        }

        // Increment the size of the queue.
        pq->size++;
        
        result = true;
    }

    return result;
}

// TODO: Check if this is correct (lines 117-121)
bool pq_dequeue(PriorityQueue* pq, Node **n)
{
    assert(pq);

    bool result = false;

    if (!pq_isEmpty(pq))
    {
        assert(n);
        assert(*n);

        // Get head of priority queue
        *n = pq->head;

        // Set new head of priority queue
        pq->head = pq->head->rightChild;

        // Decrement size of priority queue
        pq->size--;

        // Set result to true
        result = true;
    }

    return result;
}


uint32_t pq_size(PriorityQueue *pq)
{
    return pq->size;
}

// TODO: Implement PQ as a min-heap