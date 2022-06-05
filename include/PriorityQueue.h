#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H 

#include "Node.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct PriorityQueue_ 
{
    uint32_t size;        // Size of the array
    uint32_t capacity;    // Number of elements that have been allocated
    Node* front;
    Node* rear;
    Node** nodes;
} PriorityQueue;

/* Functions */
PriorityQueue* pq_create(uint32_t capacity);

void pq_delete(PriorityQueue** pq);
void pq_print(PriorityQueue *pq);

bool pq_isEmpty(PriorityQueue* pq);
bool pq_isFull(PriorityQueue* pq);
bool enqueue(PriorityQueue* pq, Node* n);
bool dequeue(PriorityQueue* pq, Node **n);

uint32_t pq_size(PriorityQueue *pq);

#endif // PRIORITYQUEUE_H