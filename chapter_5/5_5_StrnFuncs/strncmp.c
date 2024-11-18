/* Exercise 5-5. Write strncmp(s,t,n), which compares at most n characters of s to t */
/* Return <0 if s<t, 0 if s==t, >0 if s>t */

#include <stdio.h>

#define MAXLEN 30

int strncmp(char *s, char *t, int n);
int strlen(char *s);

int main()
{
    char s[MAXLEN] = "Luke, I am your father!";
    char t[MAXLEN] = "Luke, I am your fathur!";
    int res = strncmp(s, t, strlen(s));
    // Worth noting that e is less than u, because in ASCII a has a lower integer value than x
    if (res == 0)
        printf("The strings are the same\n");
    else if (res > 0)
        printf("First non matching char has a greater value in s than t\n");
    else if (res < 0)
        printf("First non matching char has a lower value in s than t\n");
}

int strncmp(char *s, char *t, int n)
{
    int counter = 0;
    while (counter < n && (*s == *t))
        counter++, s++, t++;
    int res = (counter == n) ? 0 : (*s - *t);
    return res;
}

int strlen(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
