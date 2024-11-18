/* Exercise 4-14. Define a macro swap(t,x,y) that intercahnges two arguments of type t */
#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t temp;       \
        temp = x;     \
        x = y;        \
        y = temp;     \
    }

int main()
{
    int x = 10;
    int y = 20;
    printf("Before swap: x: %d -- y: %d\n", x, y);
    swap(int, x, y);
    printf("After swap : x: %d -- y: %d\n", x, y);
}
