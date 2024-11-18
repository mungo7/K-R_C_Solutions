#include <stdio.h>

int main()
{
    long signed_num = -3L;
    unsigned long unsigned_num;

    // Explicit type conversion
    unsigned_num = (unsigned long)signed_num;

    printf("Signed number: %ld\n", signed_num);
    printf("Unsigned number: %lu\n", unsigned_num);

    return 0;
}
