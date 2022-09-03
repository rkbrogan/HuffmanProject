#include "Code.h"

#include <stdio.h>

// See bit array
Code code_init(void)
{
    // Code code = {0};

    Code code;

    // Zero out array of bits
    memset(&code, 0, sizeof(Code));

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
    //uint8_t bits[4]
    // i = 25
    bool result = false;

    if (i < ALPHABET && c->top < ALPHABET)
    {
        // Get the index of the byte
        uint32_t byte_index = i / 8;
        // byte_index = 25/ 8 = 3

        // Get the position of the bit in the byte
        uint32_t bit_index = i % 8;
        // bit_index = 25 % 8 = 1

        uint8_t mask = 1;

        mask = mask << bit_index;

        // mask = 1 << 1 = 2
        
        c->bits[byte_index] = c->bits[byte_index] | mask;
        //                    c->bits[3] | 2

        result = true;
    }

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