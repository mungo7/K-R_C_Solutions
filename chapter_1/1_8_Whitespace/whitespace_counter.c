/* Exercise 1-8. Write a program to count blanks, tabs, newlines */

#include <stdio.h>
#include <stdlib.h>

main()
{
    int c;
    int counter = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            counter++;
        }
    }
    printf("Total of spaces, tabs, newlines: %d", counter);
}