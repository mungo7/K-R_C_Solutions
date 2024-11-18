/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape sequences like \n
   and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well. */

#include <stdio.h>

#define MAXLINE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char s[] = "Hello,\t\t\nWorld!";
    char t[MAXLINE];
    printf("Original: %s\n", s);
    escape(s, t);
    printf("Escaped: %s\n", t);
    unescape(s, t);
    printf("Unescaped: %s\n", t);
}

void escape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '\t':
            t[j] = '\\';
            j++;
            t[j] = 't';
            j++;
            break;
        case '\n':
            t[j] = '\\';
            j++;
            t[j] = 'n';
            j++;
            break;
        default:
            t[j] = s[i];
            j++;
            break;
        }
    }
    t[j] = '\0';
}

void unescape(char s[], char t[])
{
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '\\':
            if (s[i + 1] == 't')
            {
                t[j] = '\t';
                i++;
            }
            else if (s[i + 1] == 'n')
            {
                t[j] = '\n';
                i++;
            }
            j++;
            break;
        default:
            t[j] = s[i];
            j++;
        }
    }
    t[j] = '\0';
}