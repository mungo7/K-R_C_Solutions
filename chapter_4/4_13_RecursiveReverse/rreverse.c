/* Exercise 4-13. Write a recursive function to reverse a string in place.*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void reverse(char s[], int i, int j);

int main()
{
    char s[MAXLEN] = "Hello, world!";
    reverse(s, 0, strlen(s) - 1);
    printf("Reversed string: %s\n", s);
}

void reverse(char s[], int i, int j)
{
    char temp;
    if (i <= j)
    {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
        reverse(s, i, j);
    }
}