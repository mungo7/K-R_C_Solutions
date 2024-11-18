/* Reverse Polish Notation Calculator */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

void handle_words(char s[]);

int main()
{
    int type;
    char s[MAXOP];
    double op2;

    printf("Reverse Polish Notation Calculator. Please enter input such that operators follow operand, e.g 10 10 + 2 pow\n\n");
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case WORD:
            handle_words(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push((int)pop() % (int)op2);
            else
                printf("error: zero divisor\n");
            break;
        case 'c':
            clear_stack();
            break;
        case 'p':
            print_stack_top();
            break;
        case 'x':
            swap_top();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

void handle_words(char s[])
{
    double op2;
    if (strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "exp") == 0)
    {
        op2 = exp(pop());
        if (op2 == HUGE_VAL || op2 == -HUGE_VAL)
            printf("error: exponential number out of range\n");
        else
            push(op2);
    }
    else if (strcmp(s, "print") == 0)
        print_stack_full();
}