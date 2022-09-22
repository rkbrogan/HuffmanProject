#pragma once
#ifndef STACK_H
#define STACK_H

#include "Node.h"

#include <stdbool.h>

typedef struct Stack {
    uint32_t top;
    uint32_t capacity;
    Node** items;
} Stack;

Stack* stack_create(uint32_t capacity);

void stack_delete(Stack** stack);

bool stack_empty(Stack* stack);

bool stack_full(Stack* stack);

uint32_t stack_size(Stack* stack);

bool stack_push(Stack* stack, Node* item);

bool stack_pop(Stack* stack, Node** item);

void stack_print(Stack* stack);

#endif // STACK_H
