/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
    It is easy to draw the histogram with the bars horizontal...a vertical orientation is more challenging */
/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 45

/* Count lines, words and characters in input */

main()
{
    int wordlengths[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; ++i)
        wordlengths[i] = 0;
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    int counter = 0;
    while ((c = getchar()) != EOF)
    {
        nc++;
        counter++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            wordlengths[counter - 1]++;
            counter = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("Word Length Frequency Histogram\n");
    for (int j = 0; j < MAX_LENGTH; j++)
    {
        if (wordlengths[j] >= 1)
        {
            printf("%2d|", j);
            for (int k = 0; k < wordlengths[j]; k++)
            {
                putchar(219);
            }
            printf("%d\n", wordlengths[j]);
        }
    }
}