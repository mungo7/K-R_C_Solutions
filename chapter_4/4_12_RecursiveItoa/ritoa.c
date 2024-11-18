/* Exercise 4-12. Recursive version of itoa */
#include <stdio.h>

void recursion(int x);

int main()
{
    int x = 1234;
    recursion(x);
}

void recursion(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x / 10)
        recursion(x / 10);
    putchar(x % 10 + '0');
}