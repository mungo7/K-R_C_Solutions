/* Exercise 1-6. Verify that the expression getchar() != is 0 or 1 */
/* Exercise 1-7. Write a program to print the value of EOF */

// Goal - Understand basic input/output functions, and EOF.
#include <stdio.h>

main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
        printf("x");
    }
    printf("%d", c);
}