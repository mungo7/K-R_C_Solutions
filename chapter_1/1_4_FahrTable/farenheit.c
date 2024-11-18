/* Exercise 1-3. Modify the temperature conversion program to print a heading above the table */
/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table */
/* Exercise 1-5. Modify the program to print the table in reverse order */
/* Exercise 1-15. Rewrite the temperature conversion program of section 1.2 to use a function for conversion */

// Goal -- Introduction to variables, for loops, functions, slightly more complicated programs

#include <stdio.h>

/* Print Farenheit to Celsius table*/

#define FAHR_LOWER 0
#define FAHR_UPPER 300
#define FAHR_STEP 20
#define CEL_LOWER 0
#define CEL_UPPER 100
#define CEL_STEP 5

fToC()
{
    float fahr, celsius;
    printf("Farenheit | Celsius\n");
    for (fahr = FAHR_LOWER; fahr <= FAHR_UPPER; fahr = fahr + FAHR_STEP)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("     %3.0fF | %6.1fC\n", fahr, celsius);
    }
}

cToF()
{
    float celsius, fahr;
    printf("\nCelsius   | Farenheit\n\a");
    for (celsius = CEL_LOWER; celsius <= CEL_UPPER; celsius = celsius + CEL_STEP)
    {
        fahr = (celsius * 9 / 5) + 32;
        printf("%8.0fC | %6.1fF\n", celsius, fahr);
    }
}

main()
{
    fToC();
    cToF();
}
