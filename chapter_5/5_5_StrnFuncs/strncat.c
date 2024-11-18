/* Exercise 5-5. Write strncat(s,t,n), which appends at most n characters of t to s */

#include <stdio.h>

#define MAXLEN 30

int strncat(char *s, char *t, int n);
int strlen(char *s);

int main()
{
    char s[MAXLEN] = "To be, or not";
    char t[MAXLEN] = " to be.";
    int res = strncat(s, t, 3);
    if (res == 1)
        printf("Success! String: %s", s);
    else
        printf("Copy failed");
}

int strncat(char *s, char *t, int n)
{
    if (n == 0 || n > strlen(t))
        return 0;
    while (*s)
        s++;
    int c = 0;
    while (c++ < n && (*s++ = *t++))
        ;
    *s = '\0';
    return 1;
}

int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}