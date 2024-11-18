/* Exercise 5-4. Write the function strend(s,t) which returns 1 if the string t occurs at the end of the string s, and zero otherwise */

#include <stdio.h>

#define MAXLEN 30

int strend(char *s, char *t);
int strlen(char *s);

int main()
{
    char s[MAXLEN] = "If I could I would";
    char t[MAXLEN] = "ould";
    int re = strend(s, t);
    printf("Output: %d", re);
}

int strend(char *s, char *t)
{
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (tLen > sLen)
        return 0;
    char *end = (s + sLen - tLen);
    while (s < end)
        s++;
    while (*t)
    {
        if (*t++ != *s++)
            return 0;
    }
    return 1;
}

int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}