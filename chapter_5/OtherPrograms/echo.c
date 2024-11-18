#include <stdio.h>

/* echo: print command line arguments */
int main(int argc, char *argv[])
{
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "\n");
    return 0;
}