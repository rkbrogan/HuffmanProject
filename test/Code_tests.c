#include "Code_tests.h"

#include "Code.h"

#include <stdlib.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

/* Write the following tests firsts:
    - code_init
    - code_set_bit
    - code_clr_bit
    - code_get_bit
    - code_print?
    
    Then implement the stack interface functions for it:
    - code_empty
    - code_full
    - code_push_bit
    - code_pop_bit
*/

// Test: Code initialization
static MunitResult test_code_init(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    munit_assert_uint(code.top, ==, 0);

    // Check that all the bits are 0
    for (uint32_t i = 0; i < ALPHABET; i++) {
        munit_assert_uint(code_get_bit(&code, i), ==, 0);
    }

    return MUNIT_OK;
}

/* code_set_bit tests */

// Test: Code set bit at first position
static MunitResult test_code_set_bit_first(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set bit at first position
    munit_assert_true(code_set_bit(&code, 0));

    // Check that top increased
    munit_assert_uint(code.top, ==, 1);
    munit_assert_uint(code.bits[0], ==, 1);

    // Confirm no other bit was set
    for (uint32_t i = 1; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code set bit at first and second position
static MunitResult test_code_set_bit_first_second(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set bits at first and second positions
    munit_assert_true(code_set_bit(&code, 0));
    munit_assert_true(code_set_bit(&code, 1));

    // Check that top increased
    munit_assert_uint(code.top, ==, 2);

    // Check that the bits are set
    munit_assert_uint(code.bits[0], ==, 3);

    // Confirm no other bit was set
    for (uint32_t i = 1; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code set bit at last position
static MunitResult test_code_set_bit_last(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set bit at last position
    munit_assert_true(code_set_bit(&code, ALPHABET - 1));

    // Check that top increased
    munit_assert_uint(code.top, ==, 1);

    // TODO: Is this correct?
    // Check that the bit is set
    munit_assert_uint(code.bits[MAX_CODE_SIZE - 1], ==, 128);

    // Confirm no other bit was set
    for (uint32_t i = 0; i < MAX_CODE_SIZE - 1; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code set bit at last and second to last position
static MunitResult test_code_set_bit_last_second_last(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set bits at last and second to last positions
    munit_assert_true(code_set_bit(&code, ALPHABET - 1));
    munit_assert_true(code_set_bit(&code, ALPHABET - 2));

    // Check that top increased
    munit_assert_uint(code.top, ==, 2);

    // Check that the bits are set
    munit_assert_uint(code.bits[MAX_CODE_SIZE - 1], ==, 192);
}

// Test: Code set bit fail at position greater than alphabet size
static MunitResult test_code_set_bit_fail(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set bit at position greater than alphabet size
    munit_assert_false(code_set_bit(&code, ALPHABET));

    // Check that top did not increase
    munit_assert_uint(code.top, ==, 0);

    // Confirm no bit was set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code set bit fail full code
static MunitResult test_code_set_bit_fail_full(const MunitParameter params[], void* data) {
    // Initialize code
    Code code = code_init();

    // Set all bits
    for (uint32_t i = 0; i < ALPHABET; i++) {
        munit_assert_true(code_set_bit(&code, i));
    }

    // Set bit at first position
    munit_assert_false(code_set_bit(&code, 0));

    // Check that top did not increase
    munit_assert_uint(code.top, ==, ALPHABET);

    // Check that all bits were set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 255);
    }

    return MUNIT_OK;
}


/* code_clr_bit tests */

// Test: Code clear bit at first index after setting it
static MunitResult test_code_clr_bit_first(const MunitParameter params[], void* data) 
{
    // Initialize code
    Code code = code_init();

    // Set bit at first position
    munit_assert_true(code_set_bit(&code, 0));

    // Confirm top increased
    munit_assert_uint(code.top, ==, 1);

    // Clear bit at first position
    munit_assert_true(code_clr_bit(&code, 0));

    // Check that top decreased
    munit_assert_uint(code.top, ==, 0);

    // Confirm no bit was set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code clear bit at tenth index after setting it
static MunitResult test_code_clr_bit_tenth(const MunitParameter params[], void* data) 
{
    // Initialize code
    Code code = code_init();

    // Set bit at tenth position
    munit_assert_true(code_set_bit(&code, 9));

    // Confirm top increased
    munit_assert_uint(code.top, ==, 1);

    // Clear bit at tenth position
    munit_assert_true(code_clr_bit(&code, 9));

    // Check that top decreased
    munit_assert_uint(code.top, ==, 0);

    // Confirm no bit was set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Code clear bit after two sets
static MunitResult test_code_clr_bit_after_two_sets(const MunitParameter params[], void* data) 
{
    // Initialize code
    Code code = code_init();

    // Set bit at first position
    munit_assert_true(code_set_bit(&code, 0));

    // Set bit at second position
    munit_assert_true(code_set_bit(&code, 1));

    // Confirm that top increased
    munit_assert_uint(code.top, ==, 2);

    // Clear bit at first position
    munit_assert_true(code_clr_bit(&code, 0));

    // Check that top decreased 
    munit_assert_uint(code.top, ==, 1);

    // Confirm that only second bit is set
    munit_assert_uint(code.bits[0], ==, 2);

    return MUNIT_OK;
}

// Test: Code clear both bits after two sets
static MunitResult test_code_clr_bit_twice(const MunitParameter params[], void* data)
{
    // Initialize code
    Code code = code_init();

    // Set bit at first position
    munit_assert_true(code_set_bit(&code, 0));

    // Set bit at second position
    munit_assert_true(code_set_bit(&code, 1));

    // Confirm that top increased
    munit_assert_uint(code.top, ==, 2);

    // Clear bit at first position
    munit_assert_true(code_clr_bit(&code, 0));

    // Clear bit at second position
    munit_assert_true(code_clr_bit(&code, 1));

    // Check that top decreased
    munit_assert_uint(code.top, ==, 0);

    // Confirm that no bit is set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}

// Test: Clear all bits
static MunitResult test_code_clr_bit_all(const MunitParameter params[], void* data)
{
    // Initialize code
    Code code = code_init();

    // Set all bits
    for (uint32_t i = 0; i < ALPHABET; i++) {
        munit_assert_true(code_set_bit(&code, i));
    }

    // Confirm that top increased
    munit_assert_uint(code.top, ==, ALPHABET);

    // Clear all bits
    for (uint32_t i = 0; i < ALPHABET; i++) {
        munit_assert_true(code_clr_bit(&code, i));
    }

    // Check that top decreased
    munit_assert_uint(code.top, ==, 0);

    // Confirm that no bit is set
    for (uint32_t i = 0; i < MAX_CODE_SIZE; i++) {
        munit_assert_uint(code.bits[i], ==, 0);
    }

    return MUNIT_OK;
}


/* code_get_bit tests */

// Test: Code get bit at first index after setting it
static MunitResult test_code_get_bit_first(const MunitParameter params[], void* data) 
{
    // Initialize code
    Code code = code_init();

    // Set bit at first position
    munit_assert_true(code_set_bit(&code, 0));

    // Confirm top increased
    munit_assert_uint(code.top, ==, 1);

    // Get bit at first position
    munit_assert_true(code_get_bit(&code, 0));

    // Check that top did not change
    munit_assert_uint(code.top, ==, 1);

    // Confirm that only first bit is set
    munit_assert_uint(code.bits[0], ==, 1);

    return MUNIT_OK;
}

/* code_empty tests */


/* code_full tests */


/* code_size tests */



// List of tests
MunitTest code_tests[] = 
{
    TEST(test_code_init),
    TEST(test_code_set_bit_first),
    TEST(test_code_set_bit_first_second),
    TEST(test_code_set_bit_last),
    TEST(test_code_set_bit_last_second_last),
    TEST(test_code_set_bit_fail),
    TEST(test_code_set_bit_fail_full),
    TEST(test_code_clr_bit_first),
    TEST(test_code_clr_bit_tenth),
    TEST(test_code_clr_bit_after_two_sets),
    TEST(test_code_clr_bit_twice),
    TEST(test_code_clr_bit_all),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};