#include "Node_tests.h"

#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

static MunitResult initialize_node()
{
    uint8_t symbol = 1;
    uint64_t frequency = 10;
    Node* n = node_create(1, 10);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    return MUNIT_OK;
}

static MunitResult confirm_returnOne()
{
    int result = returnOne();

    munit_assert_int(result, ==, 1);

    return MUNIT_OK;
}

// List of tests
MunitTest node_tests[] =
{
    TEST(initialize_node),
    TEST(confirm_returnOne),
    {NULL}
};