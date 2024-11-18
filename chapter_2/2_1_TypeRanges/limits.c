/* Exercise 2-1. Show the limits of signed and unsigned char, short, int, and long.*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("CHAR\n");
    printf("Char signed minimum: %d\n", SCHAR_MIN);
    printf("Char signed maximum: %d\n", SCHAR_MAX);
    printf("Char unsigned maximum: %d\n", CHAR_MAX);

    printf("SHORT\n");
    printf("Short signed minimum: %d\n", SHRT_MIN);
    printf("Short signed maximum: %d\n", SHRT_MAX);
    printf("Short unsigned maximum: %d\n", USHRT_MAX);

    printf("INT\n");
    printf("Int signed minimum: %d\n", INT_MIN);
    printf("Int signed maximum: %d\n", INT_MAX);
    printf("Int unsigned maximum: %u\n", UINT_MAX);

    printf("LONG\n");
    printf("Long signed minimum: %ld\n", LONG_MIN);
    printf("Long signed maximum %ld\n", LONG_MAX);
    printf("Long unsigned maximum: %lu\n", ULONG_MAX);

    printf("%d\n", sizeof(void *) * CHAR_BIT);

    return 0;
}