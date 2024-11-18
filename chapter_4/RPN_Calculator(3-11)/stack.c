#include <stdio.h>
#include "calc.h"

#define MAXVAL 100
int sp = 0;         /* Next free stack position*/
double val[MAXVAL]; /* Value stack */
double op2;

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void swap_top()
{
    if (sp > 1)
    {
        printf("event: swapping elements: op1 %g, op2 %g\n", val[sp - 1], val[sp - 2]);
        op2 = val[sp - 2];
        val[sp - 2] = val[sp - 1];
        val[sp - 1] = op2;
    }
    else
        printf("error: there are not two or more elements in stack\n");
}

void print_stack_top()
{
    if (sp > 0)
    {
        printf("event: printing top element of stack: %.8g\n", val[sp - 1]);
    }
    else
        printf("error: stack empty\n");
}

void print_stack_full()
{
    int i = sp - 1;
    printf("printing stack from index i: %d, sp: %d\n", i, sp);
    while (i >= 0)
    {
        printf("index i: %d value : %f \n", i, val[i]);
        i--;
    }
}

void clear_stack()
{
    printf("event: clearing stack\n");
    sp = 0;
}