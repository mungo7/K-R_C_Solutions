/* Exercise 2-9. Write a faster version of bitcount using x &= (x-1)*/

/* By performing x-1, the rightmost 1-bit of x is flipped, and all subsequent
    bits are set to 1. That's because the binary equivalent of any decimal number minus one
    is represented like this */

#include <stdio.h>
#include "pbin.h"

int bitcount(int x);

int main()
{
    unsigned int x = 56;
    printBinary(x);
    printBinary(x - 1);
    printf("Number of 1 bits: %d\n", bitcount(x));
}

int bitcount(int x)
{
    int b = 0;
    while (x != 0)
    {
        x &= (x - 1);
        b++;
    }
    return b;
}