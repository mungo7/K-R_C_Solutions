/* Not an exercise, just interested.
 * Read in an octal number, print the decimal and binary equivalents */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXLINE 100

int read_string(char s_num[]);
int get_octal(char s_num[], int length);
int get_decimal(char s_num[]);
int get_binary(int dec);

int main()
{
    char s_num[MAXLINE];
    printf("Enter an octal number (including preceding 0): ");
    int length = read_string(s_num);
    int oct = get_octal(s_num, length);
    int dec = get_decimal(s_num);
    int bin = get_binary(dec);
    printf("Char s_num[]: %s, Oct: %#o, Dec: %d", s_num, oct, dec);
}

int read_string(char s_num[])
{
    int i = 0;
    int c;
    while ((c = getchar()) != EOF && c != '\n')
    {
        s_num[i] = c;
        i++;
    }
    s_num[i] = '\0';
    return i;
}

int get_octal(char s_num[], int length)
{
    int i = length;
    int oct = 0;
    for (int j = 0; s_num[j] != '\0'; j++)
    {
        oct += (s_num[j] - '0') * pow(8, i - 1);
        i--;
    }
    return oct;
}

int get_decimal(char s_num[])
{
    unsigned long dec = strtol(s_num, NULL, 8);
    return dec;
    // int dec = 0, i = 0;
    // while (oct != 0)
    // {
    //     dec += (oct % 10) * pow(8, i);
    //     printf("Oct: %o, Decimal: %d, Oct mod 10: %d, i : %d\n", oct, dec, (oct % 10), i);
    //     oct /= 10;
    //     i++;
    // }
    // printf("Dec: %d", dec);
    // return dec;
}

int get_binary(int dec)
{
    return 0;
}