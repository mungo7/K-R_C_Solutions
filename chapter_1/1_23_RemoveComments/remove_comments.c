/*
 * Exercise 1-23. Write a program to remove all comments from a C program.
 */

#include <stdio.h>

#define PROGRAM 0
#define BEGIN_COMMENT 1
#define COMMENT 2
#define END_COMMENT 3
#define IN_QUOTE 4

int main(int argc, char **argv)
{
    int c, quote_c;
    int state = PROGRAM;
    while ((c = getchar()) != EOF)
    {
        if (state == PROGRAM)
        {
            if (c == '/')
            {
                state = BEGIN_COMMENT;
            }
            else if (c == '"' || c == '\'')
            {
                state = IN_QUOTE;
                quote_c = c;
                putchar(c);
            }
            else
            {
                putchar(c);
            }
        }
        else if (state == BEGIN_COMMENT)
        {
            if (c == '*')
            {
                state = COMMENT;
            }
            else
            {
                putchar('/');
                putchar(c);
                state = PROGRAM;
            }
        }
        else if (state == COMMENT)
        {
            if (c == '*')
            {
                state = END_COMMENT;
            }
        }
        else if (state == END_COMMENT)
        {
            if (c == '/')
            {
                state = PROGRAM;
            }
            else
            {
                state = COMMENT;
            }
        }
        else if (state == IN_QUOTE)
        {
            putchar(c);
            if (c == quote_c)
            {
                state = PROGRAM;
            }
        }
    }
    return 0;
}
