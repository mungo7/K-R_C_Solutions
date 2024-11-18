/* Exercise 5-7. Rewerite readlines to store lines in an array supplied by main rather than calling alloc to maintain storage
   How much faster is the program? - Answer: I used linux time function to measure the execution time. It was marginally faster after the rewrite */
/* Exercise 5-14. Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order */
/* Exercise 5-15. Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting */
/* Exercise 5-16. Add the -d ("directory order") option, which makes comparisons only on letters, numbers, and blanks.
 * Make sure it works in conjunction with -f */

#include <stdio.h> // Include directives
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 100 // Macro constants
#define MAX_LINES 1000
#define ALLOC_SIZE 5000

static char alloc_buffer[ALLOC_SIZE]; // Global variables
static char *alloc_pointer = alloc_buffer;
char *line_pointers[MAX_LINES];
int directory = 0, fold = 0, reverse = 0, numeric = 0;
int iteration = 0;

void quicksort(void *line_pointers[], int left, int right, int (*func)(void *, void *)); // Sorting functions
void swap(void *line_pointers[], int i, int j);
int strcmp_wrapper(char *x, char *y);
int numcmp(char *s1, char *s2);

int get_line(char *input, int max_line); // Input functions
int read_lines(char *line_pointers[], int max_lines);
char *alloc(int size);

void write_lines(char *line_pointers[], int lines_to_write); // Output functions

// int main(int argc, char *argv[])
// {
//     while (--argc > 0 && (*++argv)[0] == '-')
//     {
//         int c;
//         while (c = *++argv[0])
//         {
//             switch (c)
//             {
//             case 'd':
//                 directory = 1;
//                 break;
//             case 'f':
//                 fold = 1;
//                 break;
//             case 'h':
//                 printf("Help...\nUsage: ./quicksort < input\nValid arguments:\n-r: Reverse sort\n-f: Ignore case (fold)\n-d: Directory sort\n-h: Print help\n");
//                 return 1;
//             case 'r':
//                 reverse = 1;
//                 break;
//             case 'n':
//                 numeric = 1;
//                 break;
//             default:
//                 printf("Illegal argument. Valid arguments:\n-r: Reverse sort\n-f: Ignore case (fold)\n-d: Directory sort\n-h: Print help\n");
//                 return 1;
//             }
//         }
//     }
//     if (numeric && fold)
//         printf("Warning: Using -f in conjunction with -n will not alter results\n");
//     int lines_read;
//     if ((lines_read = read_lines(line_pointers, MAX_LINES)) >= 0) // Check that read lines returned without an error
//     {
//         quicksort((void **)line_pointers, 0, lines_read - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp_wrapper));
//         write_lines(line_pointers, lines_read);
//     }
//     else
//     {
//         printf("Error: read_lines returned error value\n");
//     }
// }

/* read_lines: add each line from get_line into an array of pointers, line_pointers. Return the number of lines read, or -1 for error */
int read_lines(char *line_pointers[], int max_lines)
{
    int lines_read = 0;
    int line_length;
    char *alloc_space;
    char input[MAX_LINE];
    while ((line_length = get_line(input, MAX_LINE)) > 0)
    {
        if ((alloc_space = alloc(line_length)) == NULL || lines_read > MAX_LINES) // Allocate line space with an additional space for the null terminator
            return -1;
        else
        {
            strcpy(alloc_space, input);                // Copy input into the next free space in the allocation buffer
            line_pointers[lines_read++] = alloc_space; // Point the next index in line_pointers to the start of the allocated space
        }
    }
    return lines_read;
}

/* get_line: read a single line from stdin */
int get_line(char *input, int maxline)
{
    if (input == NULL)
    {
        printf("Error: input buffer is NULL\n");
    }
    int i, c;
    for (i = 0; (i < maxline) && ((c = getchar()) != '\n') && (c != EOF); i++)
    {
        input[i] = c;
    }
    if (c == '\n') // Remove newline characters
    {
        input[i++] = '\0';
    }
    return i;
}

/* alloc: assign space in the program's allocated buffer, return error if no space available */
char *alloc(int size)
{
    if ((alloc_pointer + size) <= (alloc_buffer + ALLOC_SIZE)) // Is there enough space?
    {
        alloc_pointer += size;       // Point buffer to what will be the next free space after this operation
        return alloc_pointer - size; // Return the old buffer position so input can be inserted there
    }
}

/* write_lines: write each line from line_pointers into stdout */
void write_lines(char *line_pointers[], int lines_to_write)
{
    while (lines_to_write-- > 0)
        printf("%s\n", *line_pointers++);
}

void swap(void *line_pointers[], int i, int j)
{
    void *temp = line_pointers[i];
    line_pointers[i] = line_pointers[j];
    line_pointers[j] = temp;
}

void quicksort(void *line_pointers[], int left, int right, int (*func)(void *, void *))
{
    iteration += 1;
    if (left >= right) // Terminate the recursion once there are fewer than two elements (zero or one)
    {
        return;
    }

    int pivot = (left + right) / 2;         // Choose pivot as the middle element of partition
    swap(line_pointers, left, pivot);       // Move it to the start of the partition
    int pivot_boundary = left;              // Initialize pivot_boundary to track the position of elements less than the pivot
    for (int i = left + 1; i <= right; i++) // Iterate from the element right of the pivot to the end of the partition
    {
        if (func(line_pointers[i], line_pointers[left]) < 0) // If the current element is less than the pivot, swap it
        {
            swap(line_pointers, ++pivot_boundary, i);
        }
    }
    swap(line_pointers, left, pivot_boundary);                    // Move pivot (left) to its final position (pivot_boundary)
    quicksort(line_pointers, left, pivot_boundary - 1, (*func));  // Recursively sort the next left partition
    quicksort(line_pointers, pivot_boundary + 1, right, (*func)); // Recursively sort the next right partition
}

/* strcmp_wrapper: wrapper to allow reverse, fold, and directory functionality to control the result of strcmp more elegantly */
int strcmp_wrapper(char *x, char *y)
{
    char x_copy[strlen(x) + 1];
    char y_copy[strlen(y) + 1];
    int comparison_result;

    if (directory) // Only copy alphanumeric characters into the array copies
    {
        int i = 0;
        while (*x != '\0')
        {
            if (isalnum(*x))
            {
                x_copy[i] = *x;
                i++;
            }
            x++;
        }
        x_copy[i] = '\0';
        int j = 0;
        while (*y != '\0')
        {
            if (isalnum(*y))
            {
                y_copy[j] = *y;
                j++;
            }
            y++;
        }
        y_copy[j] = '\0';
    }
    else // If directory flag is not set, copy the full strings
    {
        strcpy(x_copy, x);
        strcpy(y_copy, y);
    }

    if (fold) // Compare characters case-independently
    {
        for (int i = 0; x_copy[i]; i++)
            x_copy[i] = tolower(x_copy[i]);
        for (int i = 0; y_copy[i]; i++)
            y_copy[i] = tolower(y_copy[i]);
    }

    comparison_result = strcmp(x_copy, y_copy);

    if (reverse) // Reverse the comparison if reverse flag set to true
        comparison_result *= -1;

    return comparison_result;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    return reverse ? (v1 > v2) - (v1 < v2) : (v1 < v2) - (v1 > v2);
}
