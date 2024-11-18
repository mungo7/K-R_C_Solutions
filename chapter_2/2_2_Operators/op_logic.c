/* Exercise 2.2. Implement getline() without the use of && or || */
#include <stdio.h>

#define MAXLINE 100

int main()
{
    int lim = MAXLINE;
    int c;
    int i = 0;
    char s[MAXLINE];

    while (i < lim - 1)
    {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    printf("String: %s", s);
}
