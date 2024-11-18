/* Exercise 4-2. Extend atof to handle scientific notation of the form: 123.45e-6 */

#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define MAXLINE 100

double atof(char s[]);
int getline(char s[], int lim);

int main()
{
    char s[MAXLINE];
    getline(s, MAXLINE);
    printf("Input as float: %f", atof(s));
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    int n = 0;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    int exponent = 0;
    int exponentsign = 1;
    if (tolower(s[i]) == 'e')
    {
        i++;
        exponentsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exponent = 0; isdigit(s[i]); i++)
        {
            exponent = 10 * exponent + (s[i] - '0');
        }
    }
    exponent *= exponentsign;
    return sign * val / power * pow(10, exponent);
}

int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
