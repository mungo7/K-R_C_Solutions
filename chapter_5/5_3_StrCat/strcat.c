/* Exercise 5-3. Write a pointer version of the function strcat shown in Chapter 2. */

#include <stdio.h>

#define MAXLINE 20

void strcat(char *s, char *t);

int main()
{
    char s[MAXLINE] = "Hello, ";
    char t[MAXLINE] = "World!";
    strcat(s, t);
    printf("%s\n", s);
}

void strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}