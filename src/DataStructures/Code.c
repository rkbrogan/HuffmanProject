#include "Code.h"

#include <stdio.h>
// TODO: See bit array
Code code_init(void)
{
    Code code;

    return code;
}

uint32_t code_size(Code *c)
{
    return c->top;
}

bool code_empty(Code *c)
{
    return c->top == 0;
}

bool code_full(Code *c)
{
    return c->top == ALPHABET;
}

bool code_set_bit(Code *c, uint32_t i)
{
    bool result = false;

    return result;
}

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