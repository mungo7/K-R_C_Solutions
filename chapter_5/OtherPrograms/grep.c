#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int mgetline(char line[], int max);

/* grep: print lines that match the pattern from the 1st arg */
int main(int argc, char *argv[])
{
    // if (argc != 2)
    // {
    //     printf("Usage: find pattern\n");
    //     return 0;
    // }

    char line[MAXLINE];
    char lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'v':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: grep -x -n pattern\n");
    else
        while (mgetline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL)
            {
                printf("%s", line);
                found++;
            }
    return found;
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
