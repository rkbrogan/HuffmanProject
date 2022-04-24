#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Node.h"

#include <stdint.h>

typedef struct PriorityQueue_ PriorityQueue;

typedef struct PriorityQueue_ 
{

} PriorityQueue;

/* Functions */
PriorityQueue* pq_create(uint32_t capacity);

void pq_delete(PriorityQueue** pq);
void pq_print(PriorityQueue *pq);

bool pq_empty(PriorityQueue* pq);
bool pq_full(PriorityQueue* pq);
bool enqueue(PriorityQueue* pq, Node* n);
bool dequeue(PriorityQueue* pq, Node **n);

uint32_t pq_size(PriorityQueue *pq);

#endif // PRIORITYQUEUE_H