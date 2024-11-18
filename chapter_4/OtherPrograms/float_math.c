#include <stdio.h>

int main()
{
    float x = 0.3;
    float y = 0.4;
    int x_dec = (int)(x * 1000); // Convert to fixed-point representation
    int y_dec = (int)(y * 1000);
    int sum_dec = x_dec + y_dec;
    float sum = sum_dec / 1000.0; // Convert back to floating-point

    printf("%.3f + %.3f = %.3f\n", x, y, sum);

    if (sum_dec == 700) // Compare in fixed-point representation
        printf("%.3f + %.3f = 0.7\n", x, y);
    else
        printf("%.3f + %.3f != 0.7\n", x, y);

    return 0;
}