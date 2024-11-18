/* Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t
    each backspace by \b, and each backslash by \\ */

#include <stdio.h>

main()
{
    char input;
    while ((input = getchar()) != EOF)
    {
        if (input == 9)
        {
            printf("\\t");
        }
        else if (input == 8)
        {
            printf("\\b");
        }
        else if (input == 92)
        {

            printf("\\\\");
        }
        else
        {
            putchar(input);
        }
    }
}