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
    Code code = code_init();

    munit_assert_uint(code.top, ==, 0);

    return MUNIT_OK;
}

/* code_set_bit tests */

// Test: Code set bit at first index
static MunitResult test_code_set_bit_1(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_true(code_set_bit(&code, 0));
    munit_assert_uint(code.top, ==, 1);

    return MUNIT_OK;
}

// Test: Code set bit at last index
static MunitResult test_code_set_bit_2(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_true(code_set_bit(&code, ALPHABET - 1));
    munit_assert_uint(code.top, ==, 1);

    return MUNIT_OK;
}


/* code_clr_bit tests */

// Test: Code clear bit at first index after setting it
static MunitResult test_code_clr_bit_1(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_true(code_set_bit(&code, 0));
    munit_assert_true(code_clr_bit(&code, 0));
    munit_assert_uint(code.top, ==, 0);

    return MUNIT_OK;
}

/* code_get_bit tests */


/* code_empty tests */


/* code_full tests */


/* code_size tests */



// List of tests
MunitTest code_tests[] = {
    TEST(test_code_init),

    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};