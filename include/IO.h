#ifndef IO_H
#define IO_H

#include "Code.h"

#include <stdint.h>

int read_bytes(int infile, uint8_t *buf, int nbytes);

int write_bytes(int outfile, uint8_t *buf, int nbytes);

bool read_bit(int infile, uint8_t *bit);

void write_code(int outfile, Code* c);

void flush_codes(int outfile);

void reset_buffer();
 
// TODO: Create pseudo code for read and write bytes
// TODO: Find binary editor to create binary files to test
// Test by comparing files

#endif