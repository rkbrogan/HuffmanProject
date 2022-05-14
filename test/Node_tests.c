#include "Node_tests.h"

#include "Node.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

static MunitResult initialize_node(const MunitParameter params[], void* data)
{
    uint8_t symbol = 1;
    uint64_t frequency = 10;
    Node* n = node_create(1, 10);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    return MUNIT_OK;
}

static MunitResult destroy_node(const MunitParameter params[], void* data)
{
    // Arrange
    Node* n = NULL;
    n = node_create(1, 10);

    // Act
    munit_assert_not_null(n);
    Node** nPtr = &n;

    // Assume 
    node_delete(nPtr);
    munit_assert_null(n);

    return MUNIT_OK;
}

static MunitResult join_nodes(const MunitParameter params[], void* data)
{
    // TODO Figure out how nodes_join works and implement this correctly
    uint8_t leftSymbol = '1';
    uint8_t rightSymbol = '2';
    uint8_t newSymbol = '$';
    
    uint64_t leftFrequency = 10;
    uint64_t rightFrequency = 11;
    uint64_t newFrequency = leftFrequency + rightFrequency;

    Node* left = node_create(leftSymbol, leftFrequency);
    Node* right = node_create(rightSymbol, rightFrequency);

    munit_assert_not_null(left);
    munit_assert_not_null(right);

    Node* new = node_join(left, right);

    munit_assert_not_null(new);

    munit_assert_uint(newSymbol, ==, new->symbol);
    munit_assert_uint(newFrequency, ==, new->frequency);

    return MUNIT_OK;
}
 
// List of tests
MunitTest node_tests[] =
{
    TEST(initialize_node),
    TEST(destroy_node),
    TEST(join_nodes),
    {NULL}
};