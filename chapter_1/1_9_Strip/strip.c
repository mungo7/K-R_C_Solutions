/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank */

#include <stdio.h>

main()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == 32)
        {
            int x;
            while ((x = getchar()) == 32)
            {
                continue;
            }
            putchar(c);
            putchar(x);
        }
        else
        {
            putchar(c);
        }
    }
}