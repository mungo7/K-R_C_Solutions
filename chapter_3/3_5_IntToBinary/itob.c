/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a
   base b character representation in the string s. In particular, hexadecimal. */
#include <stdio.h>
#include <math.h>

#define MAXLINE 100

void itob(int n, char s[], int b);

int main()
{
    int n = 255;
    char s[MAXLINE];
    int b = 16;
    itob(n, s, b);
    printf("Original Integer: %d\n", n);
    printf("Base Conversion:  %d\n", b);
    printf("Formatted string: %s\n", s);
}

void itob(int n, char s[], int b)
{
    // Get digits from n, transform base, and add to string
    int i = 0, digit = 0;
    do
    {
        digit = (n % b);
        s[i++] = (digit > 9) ? (digit - 10) + 'A' : digit + '0';
        n /= b;
    } while (n > 0);
    // Reverse the string
    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        char temp = s[j];
        s[j] = s[k];
        s[k] = temp;
    }
}

// TODO - Add support for negative numbers
// TODO - Add error handling for non-integer inputs
// TODO - Add a user input