#include <stdio.h>

main()
{
    int ascii_code;
    while ((ascii_code = getchar()) != EOF)
    {
        printf("\nInteger: %d, Ascii character: ", ascii_code);
        putchar(ascii_code);
    }
}