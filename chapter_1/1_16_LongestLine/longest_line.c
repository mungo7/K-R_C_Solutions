#include <stdio.h>
#define MAXLINE 1000
#define MAXTEXT 50000
#define MINLINE 5

int getline(char line[], int maxline);
int concat(char line[], char output[], int pos, int len);
void copy(char to[], char from[]);

/* Print longest input line */
int main()
{
    int len;
    int max;
    int pos;
    char line[MAXLINE];
    char longest[MAXLINE];
    char output[MAXLINE];

    max = 0;
    pos = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > MINLINE)
            pos = concat(line, output, pos, len);
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* There was at least one line*/
        printf("Longest line: %s", longest);
    printf("Lines over %d length:\n%s", MINLINE, output);
    return 0;
}

/* Append lines longer than MINLINE to an output string */
int concat(char line[], char output[], int pos, int len)
{
    int i;
    for (i = 0; i < len && pos < MAXTEXT; i++)
    {
        output[pos] = line[i];
        pos++;
    }
    return pos;
}

/* getline: read a line into s, return length*/
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/* copy : copy 'from' into 'to' */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}
