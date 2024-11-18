
#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 8

int getLine(char input[]);
int detab(argc, argv);

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    detab(argc, argv);
}

int detab(int argc, char *argv[])
{
    int spaces, pos, c;

    spaces = 0;
    pos = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            spaces = TABLENGTH - ((pos) % TABLENGTH);

            while (spaces > 0)
            {
                putchar('#');
                pos++;
                spaces--;
            }
        }
        else if (c == '\n')
        {
            putchar(c);
            pos = 0;
        }
        else
        {
            putchar(c);
            pos++;
        }
    }
    return 0;
}

int getLine(char input[])
{
    int c, i;
    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; i++)
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
