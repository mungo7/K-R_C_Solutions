/* Exercise 1-11. How would you test the word count program?
   What kinds of input are most likely to uncover bugs if there are any? */
// Goal -- Understand state machines, better understanding of input/outputs & error checking
/* Characters most likely to cause issues would be escape sequences, characters outside of ASCII (Unicode above 128)*/

#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }
    printf("Lines: %d, Words: %d, Characters: %d\n", nl, nw, nc);
}