/* Exercise 2-5. Write function any(s1, s2) which returns the first location in the string s1 where any character from the string s2 occurs*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello";
    char s2[] = "World!";
    int res = any(s1, s2);
    printf("Result: %d", res);
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = 0; s1[j] != '\0'; j++)
        {
            if (s2[i] == s1[j])
            {
                return j;
            }
        }
    }
    return -1;
}