/* Exercise 5-5. Write strncpy(s,t,n), which copies at most n characters of s to t */

#include <stdio.h>

#define MAXLEN 30

char *strncpy(const char *s, char *t, int n);
int strlen(char *s);

int main()
{
    char s[MAXLEN] = "That is the question...";
    char t[MAXLEN];
    char *x;
    x = strncpy(s, t, 15);
    printf("Original t array after copy     : %s\n", t);
    printf("Pointer to start of t after copy: %s\n", x);
}

char *strncpy(const char *s, char *t, int n)
{
    char *t_start = t;
    int i = 0;
    while (i++ < n && (*t++ = *s++))
        ;
    *t = '\0';
    return t_start;
}

int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
