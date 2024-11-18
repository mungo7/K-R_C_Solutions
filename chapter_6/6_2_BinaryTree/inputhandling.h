#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch())) // Ignore spaces
        ;

    if (c == '/') // Handle comments
    {
        int d;
        if ((d = getch()) == '*') // Start of a comment
        {
            while ((c = getch()) != EOF)
                if (c == '*')
                    if ((d = getch()) == '/') // End of comment
                        break;
                    else
                        ungetch(d);
            if (c == EOF)
                return EOF;
        }
        else
            ungetch(d); // Not a comment
    }

    if (c != EOF) // If c is not EOF, add to word
        *w++ = c;

    if (!isalpha(c) && c != '_' && c != '#') // If c is not alphabetic or underscore, set null terminator and return
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) // Increment w until lim is reached
    {
        if (!isalnum(*w = getch()) && *w != '_' && *w != '#') // Add next getch to word. If it is not alphanumeric or underscore, put it back on input stream and break
        {
            ungetch(*w); // Put it back on the input stream
            break;
        }
    }
    *w = '\0'; // Add null terminator
    return word[0];
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}