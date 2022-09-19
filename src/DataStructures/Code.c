#include "Code.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

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

    if (i < ALPHABET)
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

        // Set return value
        result = true;
    }

    return result;
}

// Function that clears the bit at index i in Code c
bool code_clr_bit(Code* c, uint32_t i)
{
    bool result = false;

    if (i < ALPHABET)
    {
        // Get the index of the first byte
        uint32_t byte_index = i / 8;

        // Get the position of the bit in the byte
        uint32_t bit_index = i % 8;

        uint8_t mask = 1;

        mask = mask << bit_index;

        // Flip the mask bits
        mask = ~mask;

        // Clear the bit
        c->bits[byte_index] = c->bits[byte_index] & mask;

        // Set return value
        result = true;
    }

    return result;
}

// Function that gets the bit at index i. Returns false if i is out of range or bit i is equal to 0. Returns true is and only if bit i is equal to 1.
bool code_get_bit(Code *c, uint32_t i)
{
    bool result = false;
    
    uint32_t byte_index = i / 8;

    if (i < ALPHABET && c->bits[byte_index] != 0)
    {
        uint32_t bit_index = i % 8;

        uint8_t mask = 1;

        mask = mask << bit_index;

        // Check if bit was set
        if (c->bits[byte_index] == (c->bits[byte_index] & mask))
        {
            result = true; 
        }
    }

    return result;
}

// Function that pushes bit onto the Code. Returns false if Code is full prior to push.
bool code_push_bit(Code *c, uint8_t bit)
{
    assert(bit == 0 || bit == 1);

    if (code_full(c))
    {
        return false;
    }

    bool result = bit == 1 ? code_set_bit(c, c->top) : code_clr_bit(c, c->top);

    if (result)
    {
        c->top++;
    }

    return result;
}

// Function that pops off the Code. Value of the popped bit is passed back with pointer bit. Returns false if Code is empty prior to popping bit.
bool code_pop_bit(Code *c, uint8_t *bit)
{
    assert(bit != NULL);
    assert(c != NULL);

    bool result = false;

    if (!code_empty(c))
    {
        *bit = c->bits[c->top];

        // Update c->top
        c->top--;
        result = true;
    }
    
    return result;
}

// Function that prints the Code
void code_print(Code *c)
{
    assert(c != NULL);

    uint32_t size = code_size(c);

    for (uint32_t i = 0; i < size; i++)
    {
        printf("%d", code_get_bit(c, i));
    }

    printf("\n");
}