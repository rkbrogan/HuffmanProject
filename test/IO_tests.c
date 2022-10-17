#include "IO_tests.h"

#include "defines.h"
#include "IO.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TEST(name) { (char*)#name, name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

// Test 0: Read the test binary file
static MunitResult io_test_linux_read(const MunitParameter params[], void* data)
{
    uint8_t test_bits[MAX_CODE_SIZE];

    // Generated from https://www.dcode.fr/file-data
    int f1 = open("./test/dcode-file_01010101", O_RDONLY);

    // read(fileDescriptor, buffer, bytesCount)
    int n1 = read(f1, test_bits, 1);
    munit_assert_int(close(f1), ==, 0);
    
    munit_assert_int(n1, ==, 1);

    return MUNIT_OK;
}

// Test: Read a file smaller than BLOCK (4 KB)
static MunitResult io_read_bytes_3kb(const MunitParameter params[], void* data)
{
    int inFile = open("", O_RDONLY);

    uint8_t buffer[3*1024];

    int result = read_bytes(inFile, buffer, sizeof(buffer));
    munit_assert_int(close(inFile), ==, 0);

    munit_assert_int(result, ==, sizeof(buffer));

    // Loop and check values of buffer

    return MUNIT_OK;
}


/**************************************************************/
/*************** Full collection of io tests ******************/
/**************************************************************/
MunitTest io_tests[] = {
    TEST(io_test_linux_read),
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};