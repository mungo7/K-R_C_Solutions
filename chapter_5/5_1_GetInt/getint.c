/* Exercise 5-1. Getint treats a + or - not followed by a digit as a valid representation of zero.
 * Fix it to push such a character back onto the input */

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE]; // Buffer for ungetch
int bufp = 0;      // Next free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main()
{
    int n;
    int *pn = &n;
    getint(pn);
    printf("Value of pn = %d\n", *pn);
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getchar())) // Skip whitespace
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') // If c is not a number
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar();
        if (!isdigit(c))
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getchar())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}