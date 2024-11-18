/* Exercise 6-2. Write a program that eads a C program and prints in alphabetical
 * order each group of variable names that are identical in the first 6 characters,
 * but different somewhere thereafter. Don't count words within strings and comments.
 * Make 6 a parameter that can be set from the command line. */

/* 1. Get a new word with getword
 * 2. Go through the binary tree and see if it shares first 6 characters with an existing word. If not, create a new node.
 * 3. Print each node that has >1 count
 */

#include <stdlib.h>
#include <string.h>
#include "inputhandling.h"
#include "quicksort.h"

#define MAX_WORD 100
#define MAX_WORDS 500
#define NKEYS (sizeof keytab / sizeof(struct key))

struct tnode
{
    char *words[MAX_WORDS];
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct key
{
    char *word;
    int count;
};

struct key keytab[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0},
    {"continue", 0},
    {"default", 0},
    {"do", 0},
    {"double", 0},
    {"else", 0},
    {"enum", 0},
    {"extern", 0},
    {"float", 0},
    {"for", 0},
    {"goto", 0},
    {"if", 0},
    {"int", 0},
    {"long", 0},
    {"register", 0},
    {"return", 0},
    {"short", 0},
    {"signed", 0},
    {"sizeof", 0},
    {"static", 0},
    {"struct", 0},
    {"switch", 0},
    {"typeof", 0},
    {"union", 0},
    {"unsigned", 0},
    {"void", 0},
    {"volatile", 0},
    {"while", 0},
};

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);
int binsearch(char *word, struct key tab[], int n);

static int COMPARISON_LENGTH = 6;

/* word frequency count */
int main(int argc, char *argv[])
{
    while (--argc > 0 && *++argv) // Decrement to account for function name
    {
        if ((*argv)[0] == '-') // Increment to account for function name
        {
            int c;
            while ((c = *++argv[0]) && argc-- > 0)
            {
                switch (c)
                {
                case 'n':
                    if (argc > 0)
                    {
                        COMPARISON_LENGTH = atoi(*(++argv)); // Convert the next argument to an integer
                        argc--;
                    }
                    else
                    {
                        printf("Error: -n option requires a number\n");
                        return 1; // Exit with an error code
                    }
                    break;
                default:
                    printf("Illegal argument. Usage: ./varnames -n number\n");
                    return 1; // Exit with an error code
                }
            }
        }
    }

    struct tnode *root;                           // Create a pointer to root note
    char word[MAX_WORD];                          // Create a character array
    root = NULL;                                  // Set root to null
    while (getword(word, MAX_WORD) != EOF)        // Get words until EOF
        if (binsearch(word, keytab, NKEYS) != -1) // If word is variable
            root = addtree(root, word);           //
    treeprint(root);
    return 0;
}

/* addtree: add a node with a w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int condition;

    if (p == NULL) // A new word has arrived
    {
        p = talloc(); // Make a new node
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((condition = (strncmp(p->word, w, COMPARISON_LENGTH))) == 0)
    {
        p->count++; // Repeated word
    }
    else if (condition < 0) // Less than into left subtree
        p->left = addtree(p->left, w);
    else // Greater than into right subtree
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

// /* strdup: duplicate a string into a new block of memory */
// char *strdup(char *s)
// {
//     char *p;
//     p = (char *)malloc(strlen(s) + 1); // +1 for '\0'
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }
