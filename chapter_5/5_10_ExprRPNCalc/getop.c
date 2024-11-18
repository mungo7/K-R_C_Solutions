#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char *argv, char s[])
{
    int i, c;
    while (((s[0] = c = *argv++) == ' ' || c == '\t'))
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.') /* collect operand */
    {
        if (isalpha(c))
        {
            while (isalpha(s[++i] = c = *argv++))
                ;
            s[i] = '\0';
            return WORD;
        }
        else
        {
            return c;
        }
    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = *argv++))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = *argv++))
            ;
    s[i] = '\0';
    /* once c is not equal to isdigit or isalpha, getch has gone too far */
    if (c == EOF)
        return EOF;
    return NUMBER;
}
