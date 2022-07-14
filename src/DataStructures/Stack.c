#include "Stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
    return false;
}


bool stack_pop(Stack* stack, Node** n)
{
    return false;
}


void stack_print(Stack* stack)
{
    assert(stack);

    // Walk through stack and print each node's character.
    uint32_t i = 0;
    for (i = 0; i < stack->top; i++)
    {
        printf("%c ", stack->items[i]->symbol);
    }
}