#pragma once
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H 

#include "Node.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// LOWER FREQUENCY IS HIGHER PRIORITY

/* ---- PQ NOTES ----
 * FIFO
 * Single Linked List (next node is right child)
 * Enqueue 
 * Dequeue returns the highest priority node (head of the linked list)
 */
typedef struct PriorityQueue_ 
{
    uint32_t size;          // Number of nodes in the queue
    uint32_t capacity;      // Maximum number of nodes in the queue
    Node* head;             // Pointer to the head of the queue 
    Node* tail;             // Pointer to the end of the queue
} PriorityQueue;

/* Functions */
PriorityQueue* pq_create(uint32_t capacity);

void pq_delete(PriorityQueue** pq);
void pq_print(PriorityQueue *pq);

bool pq_isEmpty(PriorityQueue* pq);
bool pq_isFull(PriorityQueue* pq);
bool pq_enqueue(PriorityQueue* pq, Node* n);
bool pq_dequeue(PriorityQueue* pq, Node **n);

uint32_t pq_size(PriorityQueue *pq);
uint32_t pq_capacity(PriorityQueue *pq);

#endif // PRIORITYQUEUE_H
