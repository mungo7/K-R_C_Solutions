/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that
 * begin at position p set to the rightmost n bits of y, leaving the other bits unchanged */

#include <stdio.h>
#include "pbin.h"

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
// void printBinary(int num);

int main()
{
    unsigned int x = 127;
    int p = 5;
    int n = 3;
    unsigned int y = 12;
    printf("Result in decimal: %u\n", setbits(x, p, n, y));
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    printf("x: ");
    printBinary(x);
    printf("p: %d, n: %d\ny: ", p, n);
    printBinary(y);

    int y_mask = (~(~0 << n));
    int setBits = (y & y_mask) << (p + 1 - n);
    int x_mask = ~(~(~0 << n) << (p + 1 - n));
    printf("x:\t\t");
    printBinary(x);
    printf("x mask:\t\t");
    printBinary(x_mask);
    printf("x masked:\t");
    printBinary(x & x_mask);
    x = x & x_mask;
    printf("Result in binary: ");
    printBinary(x | setBits);
    return x | setBits;
}

// void printBinary(int num)
// {
//     int size = sizeof(num) * 8;
//     for (int i = size - 1; i >= 0; i--)
//     {
//         int bit = (num >> i) & 1;
//         printf("%d", bit);
//     }
//     printf("\n");
// }