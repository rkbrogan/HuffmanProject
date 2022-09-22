#include "Stack_tests.h"

#include "defines.h"
#include "Stack.h"

#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// Test: Create a stack with a capacity of one
static MunitResult stack_create_with_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

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
    UNUSED(params);
    UNUSED(data);

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
    UNUSED(params);
    UNUSED(data);

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
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Delete a stack with a capacity of 10
static MunitResult stack_delete_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Delete a stack with a capacity of 100
static MunitResult stack_delete_with_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    stack_delete(&stack);
    munit_assert_null(stack);
    
    return MUNIT_OK;
}

// Test: Push a value onto an empty stack with a capacity of one
static MunitResult stack_push_with_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);

    munit_assert_true(stack_push(stack, n));

    munit_assert_int(1, ==, stack->top);
    munit_assert_int(1, ==, stack->items[0]->frequency);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push a value onto an empty stack with a capacity of 10
static MunitResult stack_push_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);

    munit_assert_true(stack_push(stack, n));

    munit_assert_int(1, ==, stack->top);
    munit_assert_int(1, ==, stack->items[0]->frequency);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push a value onto an empty stack with a capacity of 100
static MunitResult stack_push_with_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);

    munit_assert_true(stack_push(stack, n));

    munit_assert_int(1, ==, stack->top);
    munit_assert_int(1, ==, stack->items[0]->frequency);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push two values onto an empty stack with a capacity of two
static MunitResult stack_push_two_values_with_capacity_of_two(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(2);
    munit_assert_not_null(stack);

    Node* n1 = node_create('1', 1);
    Node* n2 = node_create('2', 2);
    
    munit_assert_true(stack_push(stack, n1));
    munit_assert_true(stack_push(stack, n2));
    
    // Top should be 2
    munit_assert_int(2, ==, stack->top);

    munit_assert_int(1, ==, stack->items[0]->frequency);
    munit_assert_int(2, ==, stack->items[1]->frequency);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push two values onto an empty stack with a capacity of ten
static MunitResult stack_push_two_values_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    Node* n1 = node_create('1', 1);
    Node* n2 = node_create('2', 2);
    
    munit_assert_true(stack_push(stack, n1));
    munit_assert_true(stack_push(stack, n2));
    
    // Top should be 2
    munit_assert_int(2, ==, stack->top);

    munit_assert_int(1, ==, stack->items[0]->frequency);
    munit_assert_int(2, ==, stack->items[1]->frequency);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push ten values onto an empty stack with a capacity of ten
static MunitResult stack_push_ten_values_with_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', i);
        munit_assert_true(stack_push(stack, n));
    }
    
    // Top should be 10
    munit_assert_int(10, ==, stack->top);
    
    for (int i = 0; i < 10; i++)
    {
        munit_assert_int(i, ==, stack->items[i]->frequency);
    }
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test Push three values onto an empty stack with a capacity of two
static MunitResult stack_push_three_values_with_capacity_of_two(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(2);
    munit_assert_not_null(stack);

    Node* n1 = node_create('1', 1);
    Node* n2 = node_create('2', 2);
    Node* n3 = node_create('3', 3);
    
    munit_assert_true(stack_push(stack, n1));
    munit_assert_true(stack_push(stack, n2));

    // Stack should be full
    munit_assert_false(stack_push(stack, n3));
    
    // Delete node that wasn't added to stack
    node_delete(&n3);
    
    // Top should be 2
    munit_assert_int(2, ==, stack->top);

    munit_assert_int(1, ==, stack->items[0]->frequency);
    munit_assert_int(2, ==, stack->items[1]->frequency);
    

    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Push 26 values onto an empty stack with a capacity of 26
static MunitResult stack_push_26_values_with_capacity_of_26(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(26);
    munit_assert_not_null(stack);

    for (int i = 0; i < 26; i++)
    {
        Node* n = node_create('1', i);
        munit_assert_true(stack_push(stack, n));
    }
    
    // Top should be 26
    munit_assert_int(26, ==, stack->top);
    
    for (int i = 0; i < 26; i++)
    {
        munit_assert_int(i, ==, stack->items[i]->frequency);
    }
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if stack is empty after creating a stack with a capacity of one
static MunitResult stack_empty_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    munit_assert_true(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if stack is empty after creating a stack with a capacity of ten
static MunitResult stack_empty_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    munit_assert_true(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if stack is empty after creating a stack with a capacity of one hundred
static MunitResult stack_empty_capacity_of_one_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    munit_assert_true(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if stack is empty after creating a stack with a capacity of one after a push
static MunitResult stack_empty_capacity_of_one_after_a_push(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_true(stack_push(stack, n));
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}


// Test: Check if stack is empty after creating a stack with a capacity of ten after one push
static MunitResult stack_empty_capacity_of_ten_after_one_push(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_true(stack_push(stack, n));
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if stack is empty after creating a stack with a capacity of one hundred after one push
static MunitResult stack_empty_capacity_of_one_hundred_after_one_push(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_true(stack_push(stack, n));
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of one is empty
static MunitResult stack_empty_full_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_true(stack_push(stack, n));
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of ten is empty
static MunitResult stack_empty_full_stack_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of one hundred is empty
static MunitResult stack_empty_full_stack_capacity_of_one_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    for (int i = 0; i < 100; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_false(stack_empty(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if empty stack is full of a capacity of one
static MunitResult stack_full_empty_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    munit_assert_false(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if empty stack is full of a capacity of ten
static MunitResult stack_full_empty_stack_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    munit_assert_false(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if empty stack is full of a capacity of one hundred
static MunitResult stack_full_empty_stack_capacity_of_one_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    munit_assert_false(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of one is full
static MunitResult stack_full_full_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_true(stack_push(stack, n));
    
    munit_assert_true(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of ten is full
static MunitResult stack_full_full_stack_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_true(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if full stack of a capacity of one hundred is full
static MunitResult stack_full_full_stack_capacity_of_one_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    for (int i = 0; i < 100; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_true(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if a almost full stack of a capacity of ten is full
static MunitResult stack_full_almost_full_stack_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    for (int i = 0; i < 9; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_false(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Check if a almost full stack of a capacity of one hundred is full
static MunitResult stack_full_almost_full_stack_capacity_of_one_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    for (int i = 0; i < 99; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_true(stack_push(stack, n));
    }
    
    munit_assert_false(stack_full(stack));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack size of a stack of a capacity of one
static MunitResult stack_size_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_not_null(n);

    stack_push(stack, n);

    munit_assert_uint32(stack_size(stack), ==, 1);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack size of a stack with ten elements
static MunitResult stack_size_stack_with_ten_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(15);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    munit_assert_uint32(stack_size(stack), ==, 10);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack size of a stack with one hundred elements
static MunitResult stack_size_stack_with_one_hundred_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(105);
    munit_assert_not_null(stack);

    for (int i = 0; i < 100; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    munit_assert_uint32(stack_size(stack), ==, 100);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack size of a full stack of 10 elements
static MunitResult stack_size_full_stack_of_ten_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(10);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    munit_assert_uint32(stack_size(stack), ==, 10);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack size of a full stack of one hundred elements
static MunitResult stack_size_full_stack_of_one_hundred_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(100);
    munit_assert_not_null(stack);

    for (int i = 0; i < 100; i++)
    {
        Node* n = node_create('1', 1);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    munit_assert_uint32(stack_size(stack), ==, 100);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of a stack of a capacity of one
static MunitResult stack_pop_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* n = node_create('1', 1);
    munit_assert_not_null(n);

    stack_push(stack, n);

    Node* temp;
    munit_assert_true(stack_pop(stack, &temp));
    munit_assert_uint32(temp->frequency, ==, 1);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of a stack with ten elements
static MunitResult stack_pop_stack_with_ten_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(15);
    munit_assert_not_null(stack);

    for (int i = 0; i < 10; i++)
    {
        Node* n = node_create('1', i);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    Node* temp;
    munit_assert_true(stack_pop(stack, &temp));
    munit_assert_uint32(temp->frequency, ==, 9);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of a stack with one hundred elements
static MunitResult stack_pop_stack_with_one_hundred_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(105);
    munit_assert_not_null(stack);

    for (int i = 0; i < 100; i++)
    {
        Node* n = node_create('1', i);
        munit_assert_not_null(n);

        stack_push(stack, n);
    }

    Node* temp;
    munit_assert_true(stack_pop(stack, &temp));
    munit_assert_uint32(temp->frequency, ==, 99);
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of an empty stack capacity of one
static MunitResult stack_pop_empty_stack_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(1);
    munit_assert_not_null(stack);

    Node* temp;
    munit_assert_false(stack_pop(stack, &temp));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of an empty stack with ten elements
static MunitResult stack_pop_empty_stack_with_ten_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(15);
    munit_assert_not_null(stack);

    Node* temp;
    munit_assert_false(stack_pop(stack, &temp));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

// Test: Stack pop of an empty stack with one hundred elements
static MunitResult stack_pop_empty_stack_with_one_hundred_elements(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    Stack* stack = stack_create(105);
    munit_assert_not_null(stack);

    Node* temp;
    munit_assert_false(stack_pop(stack, &temp));
    
    stack_delete(&stack);
    
    return MUNIT_OK;
}

/**************************************************************/
/************* Full collection of stack tests *****************/
/**************************************************************/
MunitTest stack_tests[] = {
    TEST(stack_create_with_capacity_of_one),
    TEST(stack_create_with_capacity_of_ten),
    TEST(stack_create_with_capacity_of_hundred),
    TEST(stack_delete_with_capacity_of_one),
    TEST(stack_delete_with_capacity_of_ten),
    TEST(stack_delete_with_capacity_of_hundred),
    TEST(stack_push_with_capacity_of_one),
    TEST(stack_push_with_capacity_of_ten),
    TEST(stack_push_with_capacity_of_hundred),
    TEST(stack_push_two_values_with_capacity_of_two),
    TEST(stack_push_two_values_with_capacity_of_ten),
    TEST(stack_push_ten_values_with_capacity_of_ten),
    TEST(stack_push_three_values_with_capacity_of_two),
    TEST(stack_push_26_values_with_capacity_of_26),
    TEST(stack_empty_capacity_of_one),
    TEST(stack_empty_capacity_of_ten),
    TEST(stack_empty_capacity_of_one_hundred),
    TEST(stack_empty_capacity_of_one_after_a_push),
    TEST(stack_empty_capacity_of_ten_after_one_push),
    TEST(stack_empty_capacity_of_one_hundred_after_one_push),
    TEST(stack_empty_full_stack_capacity_of_one),
    TEST(stack_empty_full_stack_capacity_of_ten),
    TEST(stack_empty_full_stack_capacity_of_one_hundred),
    TEST(stack_full_empty_stack_capacity_of_one),
    TEST(stack_full_empty_stack_capacity_of_ten),
    TEST(stack_full_empty_stack_capacity_of_one_hundred),
    TEST(stack_full_full_stack_capacity_of_one),
    TEST(stack_full_full_stack_capacity_of_ten),
    TEST(stack_full_full_stack_capacity_of_one_hundred),
    TEST(stack_full_almost_full_stack_capacity_of_ten),
    TEST(stack_full_almost_full_stack_capacity_of_one_hundred),
    TEST(stack_size_stack_capacity_of_one),
    TEST(stack_size_stack_with_ten_elements),
    TEST(stack_size_stack_with_one_hundred_elements),
    TEST(stack_size_full_stack_of_ten_elements),
    TEST(stack_size_full_stack_of_one_hundred_elements),
    TEST(stack_pop_stack_capacity_of_one),
    TEST(stack_pop_stack_with_ten_elements),
    TEST(stack_pop_stack_with_one_hundred_elements),
    TEST(stack_pop_empty_stack_capacity_of_one),
    TEST(stack_pop_empty_stack_with_ten_elements),
    TEST(stack_pop_empty_stack_with_one_hundred_elements),
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};


// // List of stack_create tests to put in a MunitSuite
// MunitTest stack_create_tests[] = {
//     TEST(stack_create_with_capacity_of_one),
//     TEST(stack_create_with_capacity_of_ten),
//     TEST(stack_create_with_capacity_of_hundred),
//     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
// };

// // stack_create MuintSuite
// MunitSuite stack_create_suite = {
//     (char*) "/stack/create",
//     stack_create_tests,
//     NULL,
//     1,
//     MUNIT_SUITE_OPTION_NONE
// };

// // List of stack_delete tests to put in a MunitSuite
// MunitTest stack_delete_tests[] = {
//     TEST(stack_delete_with_capacity_of_one),
//     TEST(stack_delete_with_capacity_of_ten),
//     TEST(stack_delete_with_capacity_of_hundred),
//     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
// };

// // stack_delete MunitSuite
// MunitSuite stack_delete_suite = {
//     (char*) "/stack/delete",
//     stack_delete_tests,
//     NULL,
//     1,
//     MUNIT_SUITE_OPTION_NONE
// };

// // List of stack_push tests to put in a MunitSuite
// MunitTest stack_push_tests[] = {
//     TEST(stack_push_with_capacity_of_one),
//     TEST(stack_push_with_capacity_of_ten),
//     TEST(stack_push_with_capacity_of_hundred),
//     TEST(stack_push_two_values_with_capacity_of_two),
//     TEST(stack_push_two_values_with_capacity_of_ten),
//     TEST(stack_push_ten_values_with_capacity_of_ten),
//     TEST(stack_push_three_values_with_capacity_of_two),
//     {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
// };

// // stack_push MunitSuite
// MunitSuite stack_push_suite = {
//     (char*) "/stack/push",
//     stack_push_tests,
//     NULL,
//     1,
//     MUNIT_SUITE_OPTION_NONE
// };


// MunitSuite stack_suites_array[] = {
//     &stack_create_suite,
//     &stack_delete_suite,
//     &stack_push_suite,
//     {0}
// };


// const MunitSuite stack_test_suites = {
//     (char*) "",
//     NULL,
//     stack_suites_array,
//     1,
//     MUNIT_SUITE_OPTION_NONE
// };

