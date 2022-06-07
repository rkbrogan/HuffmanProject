#include "PriorityQueue_tests.h"

#include "PriorityQueue.h"

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }


static MunitResult pq_create_capacity_of_ten(const MunitParameter params[], void* data)
{
    uint32_t capacity = 10;
    PriorityQueue* pq = pq_create(capacity);

    munit_assert_not_null(pq);
    munit_assert_int(capacity, ==, pq->capacity);

    pq_delete(&pq);
    
    return MUNIT_FAIL;
}

static MunitResult delete_pq(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

static MunitResult is_pq_empty(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

static MunitResult is_pq_full(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

static MunitResult pq_enqueue(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

static MunitResult pq_dequeue(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

static MunitResult pq_get_size(const MunitParameter params[], void* data)
{
    return MUNIT_FAIL;
}

MunitTest priorityQueue_tests[] =
{
    TEST(pq_create_capacity_of_ten),
    TEST(delete_pq),
    TEST(is_pq_empty),
    TEST(is_pq_full),
    TEST(pq_enqueue),
    TEST(pq_dequeue),
    TEST(pq_get_size),
    {NULL}
};