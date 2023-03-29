#include "IO.h"

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// TODO: Find out what to do with these
// extern bytes_read;
// extern bytes_written;

static int bitIndex = 0;

// Wrapper function to perform reads.
int read_bytes(int infile, uint8_t *buf, int nbytes)
{
    int n = 0;
    int bytesRead = 0;

    do
    {
        // Try to read remaining bytes
        n = read(infile, &buf[n], nbytes);
        // char* s = strerror(errno);
        // printf("%s", s);

        // Adjust remaining amount and update bytes read
        nbytes -= n;
        bytesRead += n;
    } while (n != 0);
    
    return bytesRead;
}

int write_bytes(int outfile, uint8_t *buf, int nbytes)
{
    int n = 0;
    int bytesWritten = 0;
    do {
        // Try to write remaining bytes
        n = write(outfile, &buf[n], nbytes);

        // Adjust remaining amount and update bytes written
        nbytes -= n;
        bytesWritten += n;
    } while (n != 0);

    return bytesWritten;
}

// Returns false if there are no more bits to read from the buffer, otherwise true.
bool read_bit(int infile, uint8_t *bit)
{
    bool status = true;

    static uint8_t bufferIndex = 0;

    // Static buffer for read_bit and write_bit (to pass to read bytes)
    static uint8_t buffer[BLOCK];

    /* 
    Index of bit in buffer (carry over from one call to the next (ex. strtok)). 
    Since it's static, it will only be initialized once.
    */
    static int bytesRead = 0;
    
    int bitsRead = bytesRead * sizeof(uint8_t) * 8;
    
    // Check if we need to fill buffer
    if (bitIndex == 0 || bitIndex % bitsRead == 0)
    {
        bytesRead = read_bytes(infile, buffer, BLOCK);

        status = bytesRead != 0;
    }

    // Handle bit if bytes have been read.
    if (status)
    {
        // Handle bit 
        int bufferByteIndex = bitIndex / 8;
        int bufferBitIndex = bitIndex % 8;

        uint8_t mask = 0x80;

        mask = mask >> bufferBitIndex;

        *bit = (buffer[bufferByteIndex] & mask) >> (7 - bitIndex);

        assert(*bit == 1 || *bit == 0);

        bitIndex++;
    }

    // Return if there are more bits to be read or not.
    return status;
}

void write_code(int outfile, Code* c)
{

}

void flush_codes(int outfile)
{
    
}

void reset_buffer()
{
    bitIndex = 0;
}