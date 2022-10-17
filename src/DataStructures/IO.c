#include "IO.h"

#include <fcntl.h>
#include <unistd.h>

// TODO: Find out what to do with these
// extern bytes_read;
// extern bytes_written;

// Wrapper function to perform reads.
int read_bytes(int infile, uint8_t *buf, int nbytes)
{
    int n = 0;

    do
    {
        // Try to read remaining bytes
        n = read(infile, &buf[n], nbytes);

        // Adjust remaining amount
        nbytes -= n;
    } while (n != 0);
    
    return nbytes;
}

int write_bytes(int outfile, uint8_t *buf, int nbytes)
{
    return 1;
}

bool read_bit(int infile, uint8_t *bit)
{
    return false;
}

void write_code(int outfile, Code* c)
{

}

void flush_codes(int outfile)
{
    
}