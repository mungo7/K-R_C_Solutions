/* Exercise 1-22. Write a program to fold long input lines into two or more lines after the last non-blank character that occurs before the n-th column of input
    Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column  */

#include <stdio.h>

#define LINE_LENGTH 20
#define TAB_LENGTH 4

int main()
{
    int c;
    int len = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            len = 0;
        }
        if (c == '\t')
        {
            len += TAB_LENGTH;
        }
        if ((len >= LINE_LENGTH) && ((c == ' ') || (c == '\t')))
        {
            // printf("Folding, Length: %d\n", len);
            putchar(c);
            putchar('\n');
            len = 0;
            continue;
        }
        len++;
        putchar(c);
    }
    return 0;
}