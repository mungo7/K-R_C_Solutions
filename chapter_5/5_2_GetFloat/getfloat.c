/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does it return? */

// Returns integer for exit status, as the float is assigned via the pointer

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
    float f;
    float *pf = &f;
    getfloat(pf);
    printf("Value of pf = %f\n", *pf);
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pf)
{
    int c, sign;
    while (isspace(c = getch())) // Skip whitespace
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') // If c is not a number

    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1; // Deal with signs
    if (c == '+' || c == '-')
    {
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pf = 0; isdigit(c); c = getch()) // Get the integer part
        *pf = 10 * *pf + (c - '0');
    *pf *= sign;

    float mantissa = 0; // Get the mantissa part
    if (c == '.')
    {
        float power = 1;
        c = getch();
        if (!isdigit(c))
        {
            ungetch(c);
            return 0;
        }
        for (mantissa = 0; isdigit(c); c = getch())
            mantissa += ((c - '0') / (power *= 10));
    }
    *pf += mantissa;
    if (c != EOF)
        ungetch(c);
    return c;
}