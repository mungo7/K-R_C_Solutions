#include <stdio.h>

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