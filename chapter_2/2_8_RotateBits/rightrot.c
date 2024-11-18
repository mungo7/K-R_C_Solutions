/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x
    rotated to the right by n bit positions */

#include <stdio.h>
#include "pbin.h"

int rightrot(unsigned int x, int n);

int main()
{
    unsigned int x = 255;
    int n = 3;
    printBinary(x);
    x = rightrot(x, n);
    printBinary(x);
}

int rightrot(unsigned int x, int n)
{
    // If n is greater than size of x, it can be modulo'd for same effect.
    int len = sizeof(unsigned int) * 8;
    n = n % len;
    // Create a bitmask of n bits, AND it with x to get the last n bits in finalBits
    unsigned int finalBits = ~(~0 << n) & x;
    // Perform the shift of x
    x = x >> n;
    // OR x with finalBits shifted into the correct position
    x = x | (finalBits << (len - n));
    return x;
}