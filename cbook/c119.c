#include <stdio.h>

/* Pointers and Arrays */

// POINTER ARRAYS; POINTERS TO POINTERS


// MULTI-DIMENSIONAL ARRAYS
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)   /* day_of_year: set day of year from month & day */
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* Three ways to pass the array daytab (above) to a function:
f(int daytab[2][13]) { ... }
f(int daytab[][13]) { ... }         // because the number of rows is irrelevant
f(int (*daytab)[13]) { ... }        // says parameter is a pointer to an array of 13 integers
WRONG: f(int *daytab[13]) { ... }   // WRONG because it declares an array of 13 pointers to integers
*/

int main()
{
    for (int y = 2019; y < 2034; ++y)
        printf("%d %d\n", y, day_of_year(y, 3, 1));     // display results for Mar 1st of each year


}

