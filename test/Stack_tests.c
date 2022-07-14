#include "Stack_tests.h"

#include "Stack.h"

#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// Test: Create a stack with a capacity of one
static MunitResult stack_create_with_capacity_of_one(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    munit_assert_int(0, ==, stack->top);
    munit_assert_int(1, ==, stack->capacity);
    munit_assert_not_null(stack->items);

    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Create a stack with a capacity of 10
static MunitResult stack_create_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    munit_assert_int(0, ==, stack->top);
    munit_assert_int(10, ==, stack->capacity);
    munit_assert_not_null(stack->items);

    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Create a stack with a capacity of 100
static MunitResult stack_create_with_capacity_of_hundred(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    munit_assert_int(0, ==, stack->top);
    munit_assert_int(100, ==, stack->capacity);
    munit_assert_not_null(stack->items);

    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Delete a stack with a capacity of one
static MunitResult stack_delete_with_capacity_of_one(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Delete a stack with a capacity of 10
static MunitResult stack_delete_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Delete a stack with a capacity of 100
static MunitResult stack_delete_with_capacity_of_hundred(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Push a value onto an empty stack with a capacity of one
static MunitResult stack_push_with_capacity_of_one(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);

    munit_assert_true(stack_push(stack, n));

    munit_assert_int(1, ==, stack->top);
    munit_assert_int(1, ==, stack->items[0]);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push a value onto an empty stack with a capacity of 10
static MunitResult stack_push_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);

    munit_assert_true(stack_push(stack, n));

    munit_assert_int(1, ==, stack->top);
    munit_assert_int(1, ==, stack->items[0]);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}



MunitTest stack_tests[] = {
    TEST(stack_create_with_capacity_of_one),
    TEST(stack_create_with_capacity_of_ten),
    TEST(stack_create_with_capacity_of_hundred),
    TEST(stack_delete_with_capacity_of_one),
    TEST(stack_delete_with_capacity_of_ten),
    TEST(stack_delete_with_capacity_of_hundred),
    TEST(stack_push_with_capacity_of_one),
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};