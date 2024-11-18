
#include <stdio.h>

int main()
{
    int p = 100;
    int *pp = &p;
    printf("p: %d\nPointer to p: %d\nMemloc of p: %p", p, *pp, &pp);
}