#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINES 5000 /* max number of lines to be sorted */
#define MAXLINE 1000  /* max length of any input line */
#define ALLOCSIZE 50000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], char lines[], int nlines);
void writelines(char *lineptr[], int nlines, int n);
int mgetline(char line[], int max);

int main(int argc, char *argv[])
{
    int c, n = 0;

    if (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            if (isdigit(c))
            {
                n *= 10;
                n += c - '0';
            }
            else
            {
                printf("Illegal input. Example usage: ./tail -10\n");
            }
        }
    }
    else
    {
        n = 10;
    }
    if (n <= 0)
    {
        printf("Invalid number of lines: %d\n", n);
        return 1;
    }
    int nlines; /* number of input lines read */
    char lines[ALLOCSIZE];

    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0)
    {
        writelines(lineptr, nlines, n);
        return 0;
    }
    else
    {
        printf("Error: input too big to tail\n");
        return 1;
    }
    return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[], char lines[], int maxlines)
{
    int len, nlines;
    char *p = lines;
    char line[MAXLINE];

    nlines = 0;
    while ((len = mgetline(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p + len > lines + ALLOCSIZE)) /* Check if maxlines is exceeded, or if the potential allocated space is exceeded */
            return -1;
        else
        {
            line[len - 1] = '\0';  /* delete newlines */
            strcpy(p, line);       /* copy line into pointer p */
            lineptr[nlines++] = p; /* add p to the array of pointers */
            p += len;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int n)
{
    if (n > nlines)
    {
        n = nlines; // Ensure we don't try to print more lines than available
    }
    lineptr += (nlines - n);
    while (n-- > 0)
        printf("%d: %s\n", (nlines - n), *lineptr++);
}

int mgetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
