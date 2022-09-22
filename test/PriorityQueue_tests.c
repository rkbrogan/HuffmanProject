#include "PriorityQueue_tests.h"

#include "defines.h"
#include "PriorityQueue.h"

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }


// O, 1, nth cases for tests

// Test 1: Create a PriorityQueue with capacity of 0
static MunitResult pq_create_capacity_of_zero(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(0);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 2: Create a PriorityQueue with capacity of 1
static MunitResult pq_create_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(1);

    munit_assert_int(pq->capacity, ==, 1);
    munit_assert_int(pq->size, ==, 0);
    munit_assert_ptr_null(pq->head);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 3: Create a PriorityQueue with capacity of 10
static MunitResult pq_create_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(10);

    munit_assert_int(pq->capacity, ==, 10);
    munit_assert_int(pq->size, ==, 0);
    munit_assert_ptr_null(pq->head);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 4: Create a PriorityQueue with capacity of 100
static MunitResult pq_create_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(100);

    munit_assert_int(pq->capacity, ==, 100);
    munit_assert_int(pq->size, ==, 0);
    munit_assert_ptr_null(pq->head);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 5: Delete a PriorityQueue with capacity of 0
static MunitResult pq_delete_capacity_of_zero(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(0);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 6: Delete a PriorityQueue with capacity of 1
static MunitResult pq_delete_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(1);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 7: Delete a PriorityQueue with capacity of 10
static MunitResult pq_delete_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(10);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 8: Delete a PriorityQueue with capacity of 100
static MunitResult pq_delete_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(100);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 9: Check if PriorityQueue is empty with capacity of 1
static MunitResult pq_empty_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(1);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 10: Check if PriorityQueue is empty with capacity of 10
static MunitResult pq_empty_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(10);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 11: Check if PriorityQueue is empty with capacity of 100
static MunitResult pq_empty_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(100);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}
// TODO: Remove this test
// Test 12: Check if PriorityQueue is full with capacity of 0
static MunitResult pq_full_capacity_of_zero(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // PriorityQueue* pq = pq_create(0);

    // munit_assert_true(pq_isFull(pq));

    // pq_delete(&pq);

    return MUNIT_OK;
}

// Test 13: Check if PriorityQueue is full with capacity of 1
static MunitResult pq_full_capacity_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(1);
    munit_assert_not_null(pq);

    Node* node = node_create('a', 1);

    pq_enqueue(pq, node);

    munit_assert_true(pq_isFull(pq));

    // node_delete(&node);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 14: Check if PriorityQueue is full with capacity of 10
static MunitResult pq_full_capacity_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(10);
    munit_assert_not_null(pq);

    uint32_t pqCapacity = pq_capacity(pq);

    for (uint32_t i = 0; i < pqCapacity; i++)
    {
        Node* node = node_create('a', i);

        pq_enqueue(pq, node);
    }

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// TODO: free all nodes from all tests!

// Test 15: Check if PriorityQueue is full with capacity of 100
static MunitResult pq_full_capacity_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(100);
    munit_assert_not_null(pq);

    for (int i = 0; i < 100; i++)
    {
        Node* node = node_create('a', i);

        pq_enqueue(pq, node);
    }

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 16: Check if PriorityQueue is full with capacity of 1
static MunitResult pq_full_capacity_of_one_after_enqueue(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(10);
    munit_assert_not_null(pq);

    Node* node = node_create('a', 1);

    pq_enqueue(pq, node);

    munit_assert_false(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 17: Dequeue a priority queue with a capacity of two
static MunitResult pq_dequeue_capacity_of_two(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(2);
    munit_assert_not_null(pq);

    Node* node1 = node_create('a', 1);
    Node* node2 = node_create('b', 2);

    pq_enqueue(pq, node1);
    pq_enqueue(pq, node2);

    Node* temp;

    pq_dequeue(pq, &temp);

    munit_assert_uint64(temp->frequency, ==, 1);
    
    munit_assert_uint32(pq->size, ==, 1);

    // Deleting node that I dequeued
    node_delete(&temp);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 18: Dequeue a priority queue with a capacity of four
static MunitResult pq_dequeue_capacity_of_four_in_order(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(4);
    munit_assert_not_null(pq);

    Node* node1 = node_create('a', 1);
    Node* node2 = node_create('b', 2);
    Node* node3 = node_create('c', 3);
    Node* node4 = node_create('d', 4);

    pq_enqueue(pq, node1);
    pq_enqueue(pq, node2);
    pq_enqueue(pq, node3);
    pq_enqueue(pq, node4);

    Node* temp;

    pq_dequeue(pq, &temp);

    munit_assert_uint64(temp->frequency, ==, 1);
    munit_assert_uint32(temp->symbol, ==, 'a');

    munit_assert_uint32(pq->size, ==, 3);

    // Deleting node that I dequeued
    node_delete(&temp);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 19: Dequeue a priority queue with a capacity of four (reverse order)
static MunitResult pq_dequeue_capacity_of_four_in_reverse_order(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(4);
    munit_assert_not_null(pq);

    Node* node1 = node_create('a', 1);
    Node* node2 = node_create('b', 2);
    Node* node3 = node_create('c', 3);
    Node* node4 = node_create('d', 4);

    // Enqueue reverse order
    pq_enqueue(pq, node4);
    pq_enqueue(pq, node3);
    pq_enqueue(pq, node2);
    pq_enqueue(pq, node1);

    Node* temp;

    pq_dequeue(pq, &temp);

    munit_assert_uint64(temp->frequency, ==, 1);
    munit_assert_uint32(temp->symbol, ==, 'a');

    munit_assert_uint32(pq->size, ==, 3);

    // Deleting node that I dequeued
    node_delete(&temp);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 20: Dequeue a priority queue with a capacity of four (random order)
static MunitResult pq_dequeue_capacity_of_four_in_random_order(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    PriorityQueue* pq = pq_create(4);
    munit_assert_not_null(pq);

    Node* node1 = node_create('a', 1);
    Node* node2 = node_create('b', 2);
    Node* node3 = node_create('c', 3);
    Node* node4 = node_create('d', 4);

    // Enqueue reverse order
    pq_enqueue(pq, node3);
    pq_enqueue(pq, node4);
    pq_enqueue(pq, node1);
    pq_enqueue(pq, node2);

    Node* temp;

    pq_dequeue(pq, &temp);

    munit_assert_uint64(temp->frequency, ==, 1);
    munit_assert_uint32(temp->symbol, ==, 'a');

    munit_assert_uint32(pq->size, ==, 3);

    // Deleting node that I dequeued
    node_delete(&temp);

    pq_delete(&pq);

    return MUNIT_OK;
} 

// TODO: Write tests for pq_size

MunitTest priorityQueue_tests[] =
{
    TEST(pq_create_capacity_of_zero),
    TEST(pq_create_capacity_of_one),
    TEST(pq_create_capacity_of_ten),
    TEST(pq_create_capacity_of_hundred),
    TEST(pq_delete_capacity_of_zero),
    TEST(pq_delete_capacity_of_one),
    TEST(pq_delete_capacity_of_ten),
    TEST(pq_delete_capacity_of_hundred),
    TEST(pq_empty_capacity_of_one),
    TEST(pq_empty_capacity_of_ten),
    TEST(pq_empty_capacity_of_hundred),
    TEST(pq_full_capacity_of_zero),
    TEST(pq_full_capacity_of_one),
    TEST(pq_full_capacity_of_ten),
    TEST(pq_full_capacity_of_hundred),
    TEST(pq_full_capacity_of_one_after_enqueue),
    TEST(pq_dequeue_capacity_of_two),
    TEST(pq_dequeue_capacity_of_four_in_order),
    TEST(pq_dequeue_capacity_of_four_in_reverse_order),
    TEST(pq_dequeue_capacity_of_four_in_random_order),
    {NULL}
};
