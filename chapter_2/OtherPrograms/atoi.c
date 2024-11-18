/* atoi: convert s to integer */
#include <stdio.h>

int main()
{
    int i, n;
    char s[] = "12345";
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        n = 10 * n + (s[i] - '0');
        printf("s[i] as char = %c, s[i] as int = %d, n = %d\n", s[i], s[i], n);
    }
    printf("Result: %d", n);
    return 0;
}