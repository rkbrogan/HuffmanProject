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
    int inFile = open("./test/test-file-1", O_RDONLY);

    int three_kb = 3 * 1024;
    int one_kb = 1024;

    uint8_t buffer[three_kb];

    int result = read_bytes(inFile, buffer, three_kb);
    munit_assert_int(close(inFile), ==, 0);

    munit_assert_int(result, ==, three_kb);

    // Loop and check values of buffer

    return MUNIT_OK;
}

// Test: Write to a file smaller than BLOCK (4 KB)
static MunitResult io_write_bytes_3kb(const MunitParameter params[], void* data)
{
    // Clear contents of file from previous test execution
    fclose(fopen("./test/test-file-2", "w"));

    // Open file
    int outFile = open("./test/test-file-2", O_WRONLY | O_CREAT, 0644);

    int three_kb = 3 * 1024;

    uint8_t buffer[three_kb];

    // Fill buffer with 0x00
    for (int i = 0; i < three_kb; i++)
    {
        if (i % 2 == 0)
        {
            buffer[i] = 0x00;
        }
        else
        {
            buffer[i] = 0x01;
        }
    }

    // Get number of bytes written
    int result = write_bytes(outFile, buffer, three_kb);
    
    // Close file
    munit_assert_int(close(outFile), ==, 0);

    munit_assert_int(result, ==, three_kb);

    return MUNIT_OK;
}


/**************************************************************/
/*************** Full collection of io tests ******************/
/**************************************************************/
MunitTest io_tests[] = {
    TEST(io_test_linux_read),
    TEST(io_read_bytes_3kb),
    TEST(io_write_bytes_3kb),
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};