/* Exercise 2-3. Write a function htoi(s) which converts a string of hexadecimal digits into its equivalent integer value */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define HEX_PREFIX 2
#define TERMINATOR 1

int htoi(char s[]);

int main()
{
    char s[] = "0XFFFF";
    printf("Hex: %s, ", s);
    int decimal = htoi(s);
    printf("Decimal: %d\n", decimal);
}

int htoi(char s[])
{
    int result = 0;
    for (int i = strlen(s) - TERMINATOR; i > 1; i--)
    {
        if (!isdigit(s[i]))
        {
            s[i] = s[i] - 'A' + 10;
        }
        result += s[i] * pow(16, i - HEX_PREFIX);
    }
    return result;
}
