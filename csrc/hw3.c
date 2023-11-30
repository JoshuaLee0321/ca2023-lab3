#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

                
uint16_t count_leading_zeros(uint64_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);

    /* count ones (population count) */
    x -= ((x >> 1) & 0x5555555555555555 /* Fill this! */);
    x = ((x >> 2) & 0x3333333333333333) + (x & 0x3333333333333333 /* Fill this! */);
    x = ((x >> 4) + x) & 0x0f0f0f0f0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);

    return (64 - (x & 0x7f));
}

uint32_t cvrt_uint32(uint64_t x)
{
    return (uint32_t)x;
}

uint16_t cvrt_uint16(uint64_t x)
{
    return (uint16_t)x;
}

int main()
{
    
    uint64_t test_data1 = 0x00003567;
    
    *((volatile uint16_t *) (2)) = cvrt_uint16(test_data1);
    

    return 0;
}