#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readline(char *line, int lim);
int readlines(char *lineptr[], int max);
void writelines(char *lineptr[], int nlines);

#define MAX_LINE 100
#define MAX_LINES 100

int main()
{
    char *lineptr[MAX_LINES];
    int nlines;
    if ((nlines = readlines(lineptr, MAX_LINES)) > 0)
    {
        printf("Number of lines read: %d\n", nlines);
        writelines(lineptr, nlines);
        return 0;
    }
    return 1;
}

void writelines(char *lineptr[], int nlines)
{
    char **it = lineptr;
    while (nlines-- > 0)
        printf("%s\n", *it++);
}

int readlines(char *lineptr[], int max)
{
    char temp[MAX_LINE];
    int count = 0;
    int i = 0;
    int x;
    while ((x = readline(temp, MAX_LINE)) != EOF && count < max)
    {
        lineptr[i] = (char *)malloc((x + 1) * sizeof(char)); // Allocate memory at the pointer address
        if (lineptr[i] != NULL)                              // Malloc returns NULL if it fails to allocate memory
        {
            strcpy(lineptr[i], temp); // Copy the line from the temp array onto the lineptr array
            i++;
            count++;
        }
        else
        {
            printf("Memory allocation failed for line %d\n", i);
            break;
        }
    }
    return count;
}

/* readline: read a line, return it's length or EOF */
int readline(char *line, int max)
{
    int c;
    int len = 0;
    char *it = line;
    while (((c = getchar()) != '\n') && (c != EOF) && (len++ < max))
    {
        *it++ = c;
    }
    *it = '\0';
    return (len > 0) ? len : EOF;
}
