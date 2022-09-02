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

// Test: Set a bit in the code
static MunitResult test_code_set_bit_one_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 1);

    // Check that bit was set
    munit_assert_uint8(code.bits[0], ==, 1);

    return MUNIT_OK;
}

// Test: Set two bits in the code
static MunitResult test_code_set_bit_two_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 1);

    // Set the bit at index 1
    munit_assert_true(code_set_bit(&code, 1));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 2);

    // Check that the bits were set
    munit_assert_uint8(code.bits[0], ==, 1);
    munit_assert_uint8(code.bits[1], ==, 1);

    return MUNIT_OK;
}

// Test: Set ten bits in the code
static MunitResult test_code_set_bit_ten_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 10; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        // Check that the bits were set
        munit_assert_uint8(code.bits[i], ==, 1);
    }

    return MUNIT_OK;
}

// Test: Set 256 bits in the code
static MunitResult test_code_set_bit_256_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 256; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        // Check that the bits were set
        munit_assert_uint8(code.bits[i], ==, 1);
    }

    return MUNIT_OK;
}

// Test: Clear a bit in the code after one bit was set
static MunitResult test_code_clr_bit_one_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 1);

    // Check that bit was set
    munit_assert_uint8(code.bits[0], ==, 1);

    // Clear the bit at index 0
    munit_assert_true(code_clr_bit(&code, 0));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 0);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[0], ==, 0);

    return MUNIT_OK;
}

// Test: Clear a bit in the code after two bits were set
static MunitResult test_code_clr_bit_two_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 1);

    // Set the bit at index 1
    munit_assert_true(code_set_bit(&code, 1));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 2);

    // Check that the bits were set
    munit_assert_uint8(code.bits[0], ==, 1);
    munit_assert_uint8(code.bits[1], ==, 1);

    // Clear the bit at index 1
    munit_assert_true(code_clr_bit(&code, 1));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 1);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[1], ==, 0);

    // Check that the other bit was not cleared
    munit_assert_uint8(code.bits[0], ==, 1);

    return MUNIT_OK;
}

// Test: Clear middle bit after 99 bits were set
static MunitResult test_code_clr_bit_middle(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 99; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        // Check that the bits were set
        munit_assert_uint8(code.bits[i], ==, 1);
    }

    // Clear the bit at index 50
    munit_assert_true(code_clr_bit(&code, 50));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 98);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[50], ==, 0);

    // Check that the other bits were not cleared
    for (uint32_t i = 0; i < 99; i++) {
        if (i != 50) {
            munit_assert_uint8(code.bits[i], ==, 1);;
        }
    }

    return MUNIT_OK;
}

// Test: Clear middle bit after 256 bits were set
static MunitResult test_code_clr_bit_256_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 256; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        // Check that the bits were set
        munit_assert_uint8(code.bits[i], ==, 1);
    }

    // Clear the bit at index 128
    munit_assert_true(code_clr_bit(&code, 128));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 255);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[128], ==, 0);

    // Check that the other bits were not cleared
    for (uint32_t i = 0; i < 256; i++) {
        if (i != 128) {
            munit_assert_uint8(code.bits[i], ==, 1);;
        }
    }

    return MUNIT_OK;
}

// Test: Clear first, middle, and last bit after 256 bits were set
static MunitResult test_code_clr_bit_256_set_first_middle_last(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 256; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        // Check that the bits were set
        munit_assert_uint8(code.bits[i], ==, 1);
    }

    // Clear the bit at index 0
    munit_assert_true(code_clr_bit(&code, 0));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 255);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[0], ==, 0);

    // Clear the bit at index 128
    munit_assert_true(code_clr_bit(&code, 128));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 254);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[128], ==, 0);

    // Clear the bit at index 255
    munit_assert_true(code_clr_bit(&code, 255));
    
    // Check that the bits size decreased
    munit_assert_uint32(code_size(&code), ==, 253);

    // Check that bit was cleared
    munit_assert_uint8(code.bits[255], ==, 0);

    // Check that the other bits were not cleared
    for (uint32_t i = 0; i < 256; i++) {
        if (i != 0 && i != 128 && i != 255) {
            munit_assert_uint8(code.bits[i], ==, 1);;
        }
    }

    return MUNIT_OK;
}

// Test: Code size is 0 when initialized
static MunitResult test_code_size_zero(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_uint32(code_size(&code), ==, 0);

    return MUNIT_OK;
}

// Test: Code size is 1 when one bit is set
static MunitResult test_code_size_one(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));
    
    // Check that the bits size increased
    munit_assert_uint32(code.top, ==, 1);

    munit_assert_uint32(code_size(&code), ==, 1);

    return MUNIT_OK;
}

// Test: Code size is 10 when ten bits are set
static MunitResult test_code_size_ten(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 10; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        munit_assert_uint32(code_size(&code), ==, i + 1);
    }

    return MUNIT_OK;
}

// Test: Code size is 256 when 256 bits are set
static MunitResult test_code_size_256(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 256; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
        
        // Check that the bits size increased
        munit_assert_uint32(code.top, ==, i + 1);

        munit_assert_uint32(code_size(&code), ==, i + 1);
    }

    return MUNIT_OK;
}

// Test: Code is empty when initialized
static MunitResult test_code_empty_true(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_true(code_empty(&code));

    return MUNIT_OK;
}

// Test: Code is not empty when one bit is set
static MunitResult test_code_empty_false(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));

    munit_assert_false(code_empty(&code));

    return MUNIT_OK;
}

// Test: Code is not full when initialized
static MunitResult test_code_full_false(const MunitParameter params[], void* data) {
    Code code = code_init();

    munit_assert_false(code_full(&code));

    return MUNIT_OK;
}

// Test: Code is not full after one bit is set
static MunitResult test_code_full_false_one_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    // Set the bit at index 0
    munit_assert_true(code_set_bit(&code, 0));

    munit_assert_false(code_full(&code));

    return MUNIT_OK;
}

// Test: Code is not full after ten bits are set
static MunitResult test_code_full_false_ten_set(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 10; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
    }

    munit_assert_false(code_full(&code));

    return MUNIT_OK;
}

// Test: Code is full after 256 bits are set
static MunitResult test_code_full_true(const MunitParameter params[], void* data) {
    Code code = code_init();

    for (uint32_t i = 0; i < 256; i++) {
        // Set the bit at index i
        munit_assert_true(code_set_bit(&code, i));
    }

    munit_assert_true(code_full(&code));

    return MUNIT_OK;
}


// List of tests
MunitTest code_tests[] = {
    TEST(test_code_init),
    TEST(test_code_set_bit_one_set),
    TEST(test_code_set_bit_two_set),
    TEST(test_code_set_bit_ten_set),
    TEST(test_code_set_bit_256_set),
    TEST(test_code_size_zero),
    TEST(test_code_size_one),
    TEST(test_code_size_ten),
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};