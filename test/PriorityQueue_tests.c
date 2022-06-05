#include "PriorityQueue_tests.h"

#include "PriorityQueue.h"

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }


static MunitResult pq_create_capacity_of_ten(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult delete_pq(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult is_pq_empty(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult is_pq_full(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult pq_enqueue(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult pq_dequeue(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
}

static MunitResult pq_get_size(const MunitParameter params[], void* data)
{
    return MUNIT_OK;
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