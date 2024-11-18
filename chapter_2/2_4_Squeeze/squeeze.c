/* Exercise 2-4. Write a squeeze(s1, s2) function that deletes any character that occurs in s2 from s1.*/
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello";
    char s2[] = "World!";
    squeeze(s1, s2);
    printf("Result: %s", s1);
}

void squeeze(char s1[], char s2[])
{
    int occurences;
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        occurences = 0;
        for (k = 0; s2[k] != '\0'; k++)
        {
            if (s1[i] == s2[k])
            {
                occurences = 1;
                break;
            }
        }
        if (occurences == 0)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
