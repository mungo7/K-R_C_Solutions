/* Exercise 3-1. Modify binsearch such that there is only one evaluation within the while loop, and evaluate the runtime difference*/
#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int x = 4;
    int n = sizeof(v) / sizeof(v[0]);
    int r = binsearch(x, v, n);
    printf("X found at index: %d\n", r);
}
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high && x != v[mid])
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}