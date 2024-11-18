/* Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line,
    where each operator or operand is a separate argument. For example, expr 2 3 4 + * */

/* IMPORTANT : If you are running this from a bash shell, and you do "expr 2 3 4 + *", bash will interpret the *
 * as a wildcard operator and provide the names of all the files in your directory to the program. You must enclose
 * the asterisk in single or double quotes '*'.  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

void handle_words(char s[]);

int main(int argc, char *argv[])
{
    int type;
    char s[MAXOP];
    double op2;
    argv++;
    argc--;
    while ((argc-- > 0) && (type = getop(*argv, s)) != EOF && *(argv++))
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
    printf("\t%.8g\n", pop());
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