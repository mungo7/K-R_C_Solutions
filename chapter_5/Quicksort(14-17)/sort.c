/* Exercise 5-7. Rewerite readlines to store lines in an array supplied by main rather than calling alloc to maintain storage
   How much faster is the program? - Answer: I used linux time function to measure the execution time. It was marginally faster after the rewrite */

/* Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order */
/* Exercise 5-15. Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000   /* max number of lines to be sorted */
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 50000 /* max allocated space for input */
char *lineptr[MAXLINES];

int mgetline(char input[], int maxline);
int readlines(char *lineptr[], char lines[], int nlines);
void writelines(char *lineptr[], int nlines);
void mqsort(void *v[], int left, int right,
            int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int rstrcmp(const char *a, const char *b);

int reverse = 0; // Global variables for flag setting
int fold = 0;

/* sort: sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0, reverse = 0;
    char lines[ALLOCSIZE];

    // if (argc > 1 && strcmp(argv[1], "-n") == 0)
    //     numeric = 1;

    int c;
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                fold = 1;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                break;
            }
    if (argc != 1)
        printf("Usage: grep -x -n pattern\n");

    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0)
    {
        mqsort((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))(numeric ? numcmp : rstrcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* rstrcmp: wrapper for strcmp to reverse the result if reverse flag is set */
int rstrcmp(const char *a, const char *b)
{
    if (fold)
        return reverse ? strcmp(*(const char **)tolower(b), *(const char **)tolower(a)) : strcmp(*(const char **)tolower(a), *(const char **)tolower(b));
    else
        return reverse ? strcmp(*(const char **)b, *(const char **)a) : strcmp(*(const char **)a, *(const char **)b);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    return reverse ? (v1 > v2) - (v1 < v2) : (v1 < v2) - (v1 > v2);
}

/* readlines: read input lines */
int readlines(char *lineptr[], char lines[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    p = lines;
    while ((len = mgetline(line, MAXLEN)) > 0)
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

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void mqsort(void *v[], int left, int right,
            int (*comp)(void *, void *)) /* sort v[left]...v[right] into increasing order */
{
    int i, last;
    void swap(void *v[], int left, int right);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left + right) / 2); // Move the pivot element to the start
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0) // Compare using the provided comparison function
            swap(v, ++last, i);         // Swap if the element is less than the pivot
    swap(v, left, last);                // Restore pivot
    mqsort(v, left, last - 1, comp);    // Recursively sort left part
    mqsort(v, last + 1, right, comp);   // Recursively sort right part
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int mgetline(char input[], int maxline)
{
    int c, i;
    for (i = 0; i < maxline && (c = getchar()) != EOF && c != '\n'; i++)
    {
        input[i] = c;
    }
    if (c == '\n')
    {
        input[i] = c;
        i++;
    }
    input[i] = '\0';
    return i;
}
