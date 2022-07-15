#include "Stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Stack will be a dynamically allocated array of Node pointers with the rear being the "top" of the stack

Stack* stack_create(uint32_t capacity)
{
    assert(capacity > 0);

    Stack *stack = malloc(sizeof(Stack));
    assert(stack);

    stack->items = malloc(sizeof(Node*) * capacity);
    assert(stack->items);

    stack->top = 0;
    stack->capacity = capacity;

    return stack;
}


void stack_delete(Stack** stack)
{
    assert(stack);
    assert(*stack);

    for (uint32_t i = 0; i < (*stack)->top; i++)
    {
        node_delete(&((*stack)->items[i]));
    }

    free((*stack)->items);
    free(*stack);

    *stack = NULL;
}


bool stack_empty(Stack* stack)
{
    return stack->top == 0;
}


bool stack_full(Stack* stack)
{
    return stack->top == stack->capacity;
}


uint32_t stack_size(Stack* stack)
{
    return stack->top;
}


bool stack_push(Stack* stack, Node* n)
{
    assert(stack);
    assert(n);

    // Bool value to return status of push operation
    bool result = false;

    if (stack_full(stack))
    {
        return result;
    }

    // Set node as the top of the stack
    stack->items[stack->top] = n;

    // Update top
    stack->top++;

    result = true;

    return result;
}


bool stack_pop(Stack* stack, Node** n)
{
    bool result = false;

    if (stack_empty(stack))
    {
        return result;
    }

    // Check if top of the stack is valid
    assert(stack->items[stack->top - 1]);

    // Set node as the top of the stack
    *n = stack->items[stack->top - 1];

    result = true;

    return result;
}


void stack_print(Stack* stack)
{
    assert(stack);

    // Walk through stack and print each node's character.
    uint32_t i = stack->top - 1;
    {
        printf("%c ", stack->items[i]->symbol);
    }
}