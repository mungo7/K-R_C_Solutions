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

#define MAX_WORD 100

struct tnode
{
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

struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);
void treeprint(struct tnode *);

/* word frequency count */
int main()
{
    struct tnode *root;                    // Create a pointer to root note
    char word[MAX_WORD];                   // Create a character array
    root = NULL;                           // Set root to null
    while (getword(word, MAX_WORD) != EOF) // Get words until EOF
        if (isalpha(word[0]))              // If word starts with alphabetic character
            root = addtree(root, word);    //
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
    else if ((condition = strcmp(w, p->word)) == 0)
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

// /* strdup: duplicate a string into a new block of memory */
// char *strdup(char *s)
// {
//     char *p;
//     p = (char *)malloc(strlen(s) + 1); // +1 for '\0'
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }
