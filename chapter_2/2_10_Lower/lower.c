/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional
   expression rather than if-else */

#include <stdio.h>

int lower(int c);

int main()
{
    int c = 65;
    printf("%c\n", c);
    printf("%c\n", lower(c));
}

int lower(int c)
{
    c = (c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c;
}