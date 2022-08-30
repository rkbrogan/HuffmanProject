#include "Code_tests.h"

#include "Code.h"

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