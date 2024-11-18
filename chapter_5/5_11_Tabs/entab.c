/* Exercise 5-11. Modify entab and detab to accept a list of tab stops as arguments */

// Plan
// e.g entab 8 10 12 4
// after each tabstop is reached, replace the tablength with the next argument until the end of argv
// after reaching the end of argv, use default TABLENGTH
// entab should replace any spaces between the end of a word and a tabstop with a tab, any remaining spaces should remain spaces
// therefore with a tabstop of 10, "hello    hello" should become hello~hello
/* once the tabstop is updated, the condition ((pos % tabstop) != 0) is based on the new tabstop value,
   therefore, ./entab 10 8, input "hello    hello    hello" evaluates to "hello~hello~-hello" correctly, as the new tabstops are evaluated
   as multiples of 8  */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char input[]);
int entab(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    printf("Number of arguments: %d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    entab(argc, argv);
}

int entab(int argc, char *argv[])
{
    int tablength = TABLENGTH;
    if (argc > 1)
    {
        argv++;
        tablength = atoi(*argv);
    }
    int spaces, tabs, prevtabs, pos, c;
    spaces = tabs = prevtabs = 0;
    pos = 1;
    while ((c = getchar()) != EOF)
    {
        if (pos > (tablength + prevtabs)) // Handle updating of tabstop
        {
            prevtabs += tablength;
            if (*(argv + 1)) // Update tabstop
            {
                argv++;
                tablength = atoi(*argv);
            }
            else
                tablength = TABLENGTH; // Code could be improved to not continue to set to default once argv is exhausted
        }
        if (c == ' ') // If a space is encountered, add to spaces variable, and replace spaces with a tab when a tabstop is reached
        {
            if ((pos % (tablength)) != 0) // If the tabstop is not yet reached
            {
                spaces++;
            }
            else // If the tabstop is reached
            {
                tabs++;
                spaces = 0;
            }
        }
        else // If c is a character instead of a blank, handle previous blanks then insert character
        {
            if (spaces > 0 && ((pos % tablength) == 0)) // Handle case where new character is on tabstop
            {
                tabs++;
                spaces = 0;
            }
            for (; tabs > 0; tabs--)
            {
                putchar('~');
            }
            for (; spaces > 0; spaces--)
            {
                putchar('-');
            }
            putchar(c);

            if (c == '\n')
            {
                pos = 0;
            }
        }
        pos++;
    }
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
