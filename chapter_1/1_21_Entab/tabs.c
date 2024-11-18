/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop */
/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing */

#include <stdio.h>

#define MAXLINE 1000
#define TABLENGTH 4

int getLine(char input[]);
int enTab();
int deTab();

int main()
{
    printf("Which mode would you like to use?\n1 for EnTab\n2 for DeTab\nEnter number: ");
    char input = getchar();
    if (input == '1')
    {
        printf("You have selected enTab. Input your data below");
        enTab();
    }
    else if (input == '2')
    {
        printf("You have selected deTab. Input your data below:");
        deTab();
    }
    else
    {
        printf("\nInput not recognized.");
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

int deTab()
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

int enTab()
{
    int spaces, tabs, pos, c;
    spaces = tabs = pos = 0;

    while ((c = getchar()) != EOF)
    {
        /* If a space is encountered, check how many spaces, then replace each 4 spaces with a tab */
        if (c == ' ')
        {
            if ((pos % TABLENGTH) != 0)
            {
                spaces++;
            }
            else
            {
                tabs++;
                spaces = 0;
            }
        }
        else
        {
            for (; tabs > 0; tabs--)
            {
                putchar('x');
            }
            for (; spaces > 0; spaces--)
            {
                putchar('y');
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