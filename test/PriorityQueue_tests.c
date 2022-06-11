#include "PriorityQueue_tests.h"

#include "PriorityQueue.h"

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }


// O, 1, nth cases for tests

// Test 1: Create a PriorityQueue with capacity of 0
static MunitResult pq_create_capacity_of_zero(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(0);

    munit_assert_int(pq->capacity, ==, 0);
    munit_assert_int(pq->size, ==, 0);
    munit_assert_ptr_null(pq->head);

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 2: Create a PriorityQueue with capacity of 1
static MunitResult pq_create_capacity_of_one(const MunitParameter params[], void* data)
{
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
    PriorityQueue* pq = pq_create(0);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 6: Delete a PriorityQueue with capacity of 1
static MunitResult pq_delete_capacity_of_one(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(1);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 7: Delete a PriorityQueue with capacity of 10
static MunitResult pq_delete_capacity_of_ten(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(10);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 8: Delete a PriorityQueue with capacity of 100
static MunitResult pq_delete_capacity_of_hundred(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(100);

    pq_delete(&pq);

    munit_assert_ptr_null(pq);

    return MUNIT_OK;
}

// Test 9: Check if PriorityQueue is empty with capacity of 0
static MunitResult pq_empty_capacity_of_zero(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(0);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 10: Check if PriorityQueue is empty with capacity of 1
static MunitResult pq_empty_capacity_of_one(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(1);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 11: Check if PriorityQueue is empty with capacity of 10
static MunitResult pq_empty_capacity_of_ten(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(10);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 12: Check if PriorityQueue is empty with capacity of 100
static MunitResult pq_empty_capacity_of_hundred(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(100);

    munit_assert_true(pq_isEmpty(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 13: Check if PriorityQueue is full with capacity of 0
static MunitResult pq_full_capacity_of_zero(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(0);

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 14: Check if PriorityQueue is full with capacity of 1
static MunitResult pq_full_capacity_of_one(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(1);
    munit_assert_not_null(pq);

    Node* node = node_create('1', 1);

    pq_enqueue(pq, node);

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 15: Check if PriorityQueue is full with capacity of 10
static MunitResult pq_full_capacity_of_ten(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(10);
    munit_assert_not_null(pq);

    for (int i = 0; i < 10; i++)
    {
        Node* node = node_create('1', i);

        pq_enqueue(pq, node);
    }

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 16: Check if PriorityQueue is full with capacity of 100
static MunitResult pq_full_capacity_of_hundred(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(100);
    munit_assert_not_null(pq);

    for (int i = 0; i < 100; i++)
    {
        Node* node = node_create('1', i);

        pq_enqueue(pq, node);
    }

    munit_assert_true(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}

// Test 17: Check if PriorityQueue is full with capacity of 1
static MunitResult pq_full_capacity_of_one_after_enqueue(const MunitParameter params[], void* data)
{
    PriorityQueue* pq = pq_create(10);
    munit_assert_not_null(pq);

    Node* node = node_create('1', 1);

    pq_enqueue(pq, node);

    munit_assert_false(pq_isFull(pq));

    pq_delete(&pq);

    return MUNIT_OK;
}


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
    TEST(pq_empty_capacity_of_zero),
    TEST(pq_empty_capacity_of_one),
    TEST(pq_empty_capacity_of_ten),
    TEST(pq_empty_capacity_of_hundred),
    TEST(pq_full_capacity_of_zero),
    TEST(pq_full_capacity_of_one),
    TEST(pq_full_capacity_of_ten),
    TEST(pq_full_capacity_of_hundred),
    TEST(pq_full_capacity_of_one_after_enqueue),
    {NULL}
};