/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line opf input, and to delete entirely blank lines */
/* Exercise 1-19. Write a function reverse(s), that reverses the character string s. Use it to write a program that reverses its input
    a line at a time */
#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int removeBlanks(char input[], int len);
void reverseString(char input[], int len);

int main()
{
    char line[MAXLINE];
    int len;
    printf("Input: ");
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        len = removeBlanks(line, len);
        printf("Stripped: %s\n", line);
        reverseString(line, len);
        printf("Reversed: %s\n", line);
        printf("Input: ");
    }
    return 0;
}

int removeBlanks(char input[], int len)
{
    int i;
    for (i = len - 2; i >= 0; i--)
    {
        if (input[i] != '\t' && input[i] != ' ')
            break;
    }
    input[i + 1] = '\0';
    return i + 2;
}

void reverseString(char input[], int len)
{
    char temp[len];
    int j = 0;
    /* len-2 prevents assignment for the backspace and terminating characters */
    for (int i = len - 2; i >= 0; i--)
    {
        temp[j] = input[i];
        j++;
    }
    temp[len - 1] = '\0';
    copy(input, temp);
}

/* getline: read a line into s, return length.*/
int getLine(char s[], int lim)
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