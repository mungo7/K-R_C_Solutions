/* Exercise 3.3. Write a function expand(s1, s2) that expands shorthand notations
   like a-z in the string s1 into the equivalent complete list abc...xyz. */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "-a-z1-9hello-";
    char s2[MAXLINE];
    expand(s1, s2);
    printf("Resulting string: %s\n", s2);
}

void expand(char s1[], char s2[])
{
    int i, j;
    char c;
    i = j = 0;

    while (s1[i] != '\0')
    {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0' && s1[i + 1] != '-')
        {
            for (c = s1[i - 1] + 1; c < s1[i + 1]; c++)
            {
                s2[j++] = c;
            }
            i++;
        }
        else
        {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';
}