#include "Node_tests.h"

#include "defines.h"
#include "Node.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// Test 1: Initialize a node with a symbol and frequency of 0
static MunitResult node_create_single_node_with_frequency_of_zero(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);
 
    uint8_t symbol = '1';
    uint64_t frequency = 0;
    Node* n = node_create(symbol, frequency);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 2: Initialize a node with a symbol and frequency of 1
static MunitResult node_create_single_node_with_frequency_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    uint8_t symbol = '1';
    uint64_t frequency = 1;
    Node* n = node_create(symbol, frequency);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    node_delete(&n);

    return MUNIT_OK;
}


// Test 3: Initialize a node with a symbol and frequency of 10
static MunitResult node_create_single_node_with_frequency_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    uint8_t symbol = '1';
    uint64_t frequency = 10;
    Node* n = node_create(symbol, frequency);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 4: Initialize a node with a symbol and frequency of 100
static MunitResult node_create_single_node_with_frequency_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    uint8_t symbol = '1';
    uint64_t frequency = 100;
    Node* n = node_create(symbol, frequency);

    munit_assert_not_null(n);
    munit_assert_int(symbol, ==, n->symbol);
    munit_assert_int(frequency, ==, n->frequency);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 5: Delete a node with a symbol and frequency of 0
static MunitResult node_delete_after_creation_with_frequency_of_zero(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // Arrange
    Node* n = NULL;
    n = node_create('1', 0);

    // Act
    munit_assert_not_null(n);
    Node** nPtr = &n;

    // Assume 
    node_delete(nPtr);
    munit_assert_null(n);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 6: Delete a node with a symbol and frequency of 1
static MunitResult node_delete_after_creation_with_frequency_of_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // Arrange
    Node* n = NULL;
    n = node_create('1', 1);

    // Act
    munit_assert_not_null(n);
    Node** nPtr = &n;

    // Assume 
    node_delete(nPtr);
    munit_assert_null(n);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 7: Delete a node with a symbol and frequency of 10
static MunitResult node_delete_after_creation_with_frequency_of_ten(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // Arrange
    Node* n = NULL;
    n = node_create('1', 10);

    // Act
    munit_assert_not_null(n);
    Node** nPtr = &n;

    // Assume 
    node_delete(nPtr);
    munit_assert_null(n);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 8: Delete a node with a symbol and frequency of 100
static MunitResult node_delete_after_creation_with_frequency_of_hundred(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // Arrange
    Node* n = NULL;
    n = node_create('1', 100);

    // Act
    munit_assert_not_null(n);
    Node** nPtr = &n;

    // Assume 
    node_delete(nPtr);
    munit_assert_null(n);

    node_delete(&n);

    return MUNIT_OK;
}

// Test 9: Join two nodes with a symbol and frequency of 0 and 1
static MunitResult node_join_two_nodes_with_frequency_of_zero_and_one(const MunitParameter params[], void* data)
{
    UNUSED(params);
    UNUSED(data);

    // Arrange
    // Set up n1
    uint32_t n1_symbol = '1';
    uint64_t n1_frequency = 0;
    Node* n1 = node_create(n1_symbol, n1_frequency);

    // Set up n2
    uint32_t n2_symbol = '2';
    uint64_t n2_frequency = 1;
    Node* n2 = node_create(n2_symbol, n2_frequency);

    // Join nodes
    uint32_t new_symbol = '$';
    Node* n = node_join(n1, n2);

    // Act
    // Test that new node has new symbol and sum of joined nodes' frequencies
    munit_assert_not_null(n);
    munit_assert_uint32(n->symbol, ==, new_symbol);
    munit_assert_uint64(n->frequency, ==, n1_frequency + n2_frequency);

    // Test that new node's left child is n1
    munit_assert_not_null(n->leftChild);
    munit_assert_uint32(n->leftChild->symbol, ==, n1_symbol);
    munit_assert_uint64(n->leftChild->frequency, ==, n1_frequency);

    // Test that new node's right child is n2
    munit_assert_not_null(n->rightChild);
    munit_assert_uint32(n->rightChild->symbol, ==, n2_symbol);
    munit_assert_uint64(n->rightChild->frequency, ==, n2_frequency);

    node_delete(&n);
    node_delete(&n1);
    node_delete(&n2);

    return MUNIT_OK;
}

// List of tests
MunitTest node_tests[] =
{
    TEST(node_create_single_node_with_frequency_of_zero),
    TEST(node_create_single_node_with_frequency_of_one),
    TEST(node_create_single_node_with_frequency_of_ten),
    TEST(node_create_single_node_with_frequency_of_hundred),
    TEST(node_delete_after_creation_with_frequency_of_zero),
    TEST(node_delete_after_creation_with_frequency_of_one),
    TEST(node_delete_after_creation_with_frequency_of_ten),
    TEST(node_delete_after_creation_with_frequency_of_hundred),
    TEST(node_join_two_nodes_with_frequency_of_zero_and_one),
    {NULL}
};
