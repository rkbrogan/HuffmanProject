#include "PriorityQueue.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

PriorityQueue* pq_create(uint32_t capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

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
    assert(pq->capacity > 0);

    assert(n);
    assert('a' <= n->symbol && n->symbol <= 'z');
    // assert(n->frequency >= 0);

    bool result = false;

    // If pq is empty, set to head of list
    if (pq_isEmpty(pq))
    {
        pq->head = n;
        pq->tail = n;

        // Update pq
        pq->size++;

        result = true;
    }
    else if (!pq_isFull(pq))
    {
        // Node to iterate through pq
        Node* temp = pq->head;

        // Special case; check the head node's frequency
        if (temp->frequency > n->frequency)
        {
            // Set up new location of head
            n->rightChild = temp;
            pq->head = n;

            result = true;
        }
        else 
        {
            // Walk through list to find a node with a higher frequency
            while (temp->rightChild != NULL && result == false)
            {
                if (temp->rightChild->frequency > n->frequency)
                {
                    // Set position of new node to be before temp->rightChild
                    n->rightChild = temp->rightChild;
                    
                    // Set temp to be node before new node
                    temp->rightChild = n;

                    result = true;
                }

                temp = temp->rightChild;
            }

            // If we've approached the end, set new node as the tail
            if (temp->rightChild == NULL && result != true)
            {
                temp->rightChild = n;
                pq->tail = n;

                result = true;
            }
        }

        // Update pq->size if enqueue was successful
        if (result == true)
        {
            pq->size++;
        }

        return result;

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