#include "Code.h"

#include <stdio.h>
// See bit array
Code code_init(void)
{
    Code code;

    code.top = 0;

    return code;
}

// Function that returns the size of Code c
uint32_t code_size(Code *c)
{
    return c->top;
}

// Function that returns true if Code c is empty
bool code_empty(Code *c)
{
    return c->top == 0;
}

// Function that returns true if Code c is full
bool code_full(Code *c)
{
    return c->top == ALPHABET;
}

// Function that sets the bit at index i in Code c
bool code_set_bit(Code *c, uint32_t i)
{
    bool result = false;

    c->top++;
    return result;
}

// Function that clears the bit at index i in Code c
bool code_clr_bit(Code* c, uint32_t i)
{
    bool result = false;

    return result;
}

bool code_get_bit(Code *c, uint32_t i)
{
    bool result = false;

    return result;
}

bool code_push_bit(Code *c, uint8_t bit)
{
    bool result = false;

    return result;
}

bool code_pop_bit(Code *c, uint8_t *bit)
{
    bool result = false;

    return result;
}

void code_print(Code *c)
{
    for (uint32_t i = 0; i < c->top; i++) {
        printf("%d", c->bits[i]);
    }
    printf("\n");
}