/* Exercise 3-6. Write an itoa function that takes three arguments instead of two.
   The third argument is a minimum field width; the converted number must be padded
   with blanks on the left if necessary to make it wide enough */

#include <stdio.h>
#include <limits.h>
#include <math.h>

#define MAXLEN 12

void itoa(int num, char s[], int padding);

int main(void)
{
    int min = -pow(2, 31);
    char buffer[MAXLEN];
    int padding = 15;
    itoa(min, buffer, padding);

    // Output
    printf("Integer: %13d\n", min);
    printf("As String: %s\n", buffer);

    return 0;
}

void itoa(int num, char s[], int padding)
{
    char temp[MAXLEN];
    int i = 0, j = 0;
    unsigned int n;
    if (num < 0)
        n = (unsigned int)(-num);
    else
        n = (unsigned int)num;
    for (i; i <= MAXLEN - 1 && n != 0; i++)
    {
        temp[i] = (n % 10) + '0';
        n /= 10;
    }
    if (num < 0)
        temp[i++] = '-';
    s[i] = '\0';
    int remainder = padding - i;
    // add padding and lengthen string
    if (remainder > 0)
    {
        i += remainder;
        printf("Remainder: %d\n", remainder);
        while (remainder > 0)
        {
            s[j] = ' ';
            j++;
            remainder--;
        }
    }
    // i now acts as a measure of the length of the string
    for (j; j <= i; j++)
    {
        s[j] = temp[i - j - 1];
    }
    s[i] = '\0';
}
