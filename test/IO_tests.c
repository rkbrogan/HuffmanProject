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
    // uint8_t bits[MAX_CODE_SIZE];
    char test_bits[MAX_CODE_SIZE];

    int f1 = open("./test/dcode-file_01010101", O_RDONLY);
    // read(fileDescriptor, buffer, bytesCount)
    int n1 = read(f1, test_bits, 8);

    printf("\t %d", n1);

    return MUNIT_OK;
}





/**************************************************************/
/*************** Full collection of io tests ******************/
/**************************************************************/
MunitTest io_tests[] = {
    TEST(io_test_linux_read),
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};