/* Exercise 6-1. Book version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version. */

#include <stdio.h> // Preprocessor directives
#include <ctype.h>
#include <string.h>

#define MAXWORD 100 // Macro constants
#define BUFSIZE 100
struct key // Key structure and array definition
{
    char *word;
    int count;
} keytab[] = {
    "#define", 0,
    "#include", 0,
    "_underscore", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "struct", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char *, int); // Function declarations
int binsearch(char *word, struct key tab[], int n);

/* count C keywords */
int main()
{
    int n;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) || word[0] == '_' || word[0] == '#')
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

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