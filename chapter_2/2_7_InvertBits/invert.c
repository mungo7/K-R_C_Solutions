/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted */
#include <stdio.h>

int invert(unsigned int x, int n, int p);
void printBinary(int num);

int main()
{
    unsigned int x = 200;
    int n = 3;
    int p = 7;
    x = invert(x, n, p);
    printf("Result in binary: ");
    printBinary(x);
    printf("Result in decimal: %d\n", x);
}

int invert(unsigned int x, int n, int p)
{
    printf("x:\t");
    printBinary(x);
    int x_mask = (~(~0 << n) << (p + 1 - n));
    printf("x_mask: ");
    printBinary(x_mask);
    return x ^= x_mask;
}

void printBinary(int num)
{
    int size = sizeof(num) * 8;
    for (int i = size - 1; i >= 0; i--)
    {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}