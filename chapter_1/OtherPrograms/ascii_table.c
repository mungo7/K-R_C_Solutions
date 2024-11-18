#include <stdio.h>

#define MAX_LIMIT 127
main()
{
    for (int i = 0; i < MAX_LIMIT; i++)
    {
        printf("|Digit: %d, Ascii: %3c|\n", i, i);
    }
}