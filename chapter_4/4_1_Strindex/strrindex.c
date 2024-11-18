/* Exercise 4-1. Write the function strrindex(s,t), which returns the position
    of the rightmost occurence of t in s, or -1 if there is none.*/

#include <stdio.h>
#include <string.h>

int strrindex(char source[], char pattern[]);

int main()
{
    char source[] = "Woulda coulda shoulda";
    char pattern[] = "oulda";
    int index = strrindex(source, pattern);
    printf("Rightmost index of pattern start: %d", index);
}

int strrindex(char s[], char t[])
{
    int i, j, k;
    printf("strlen(s): %d\n", strlen(s));
    printf("strlen(t): %d\n", strlen(t));
    for (i = strlen(s) - 1; i != 0; i--)
    {
        for (j = i, k = strlen(t) - 1; k != 0 && s[j] == t[k]; j--, k--)
            ;
        if (k == 0)
            return j;
    }
    return -1;
}