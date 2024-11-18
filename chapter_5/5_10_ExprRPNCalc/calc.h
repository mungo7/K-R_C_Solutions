#include <string.h>

#define NUMBER '0'
#define WORD '1'

/* stack */
void push(double);
double pop(void);
void swap_top();
void print_stack_top();
void print_stack_full();
void clear_stack();

int getop(char *, char[]);
int getch(void);
void ungetch(int);
void ungets(char[]);