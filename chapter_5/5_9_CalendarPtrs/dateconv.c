/* Exercise 5-8. Add error checking to the functions */
/* Exercise 5-9. Rewrite  the routines day_of_year and month_day with pointers instead of indexing */

#include <stdio.h>
#include <stdlib.h>

static int daytab[2][13] = {/* char can store small non-character integers */
                            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                            {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);

int main()
{
    int year = 2004;
    int month = 11;
    int day = 30;
    int dayOfYr = day_of_year(year, month, day);
    printf("The yearday of %d/%d/%d, was %d\n", day, month, year, dayOfYr);
    month_day(year, dayOfYr, &month, &day);
    printf("After using month_day to set day & month, the date is %d/%d/%d\n", day, month, year);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    if (month > 12 || month < 1 || day > 31 || day < 1)
    {
        printf("error: day or month out of bounds\n");
        exit(1);
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; /* calculate if leap year - result will be zero or one therefore subscriptable */
    if (day > daytab[leap][month])
    {
        printf("%d/%d/%d - day is greater than number of days in given month\n", day, month, year);
        exit(1);
    }
    int *p = daytab[leap];
    while (--month)
        day += *p++;
    // for (i = 1; i < month; i++) /* for day in month*/
    //     day += daytab[leap][i]; /* increment day by all previous months */
    return day;
}

/* month_day: set month, day from day of year*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (*pmonth > 12 || *pmonth < 1 || *pday > 31 || *pday < 1)
    {
        printf("error: day or month out of bounds\n");
        exit(1);
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (leap && yearday > 366 || (!leap && yearday > 365) || yearday < 1)
    {
        printf("error: yearday out of bounds\n");
        exit(1);
    }
    int *p = daytab[leap];
    for (*p; yearday > *p; p++)
        yearday -= *p;
    *pmonth = i;
    *pday = yearday;
}
