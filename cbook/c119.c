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
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
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

static char *name[] = {
    "Illegal month",
    "January", "Feburary", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

static char *abbrev[] = {
    "illegal", "Jan", "Feb", "Mar"
};

static char aname[][15] = {
    "illegal", "Jan", "Feb", "Mar"
};

// INITIALIZATION OF POINTER ARRAYS
char *month_name(int n)     /* month_name: return name of n-th month */
{
    return (n < 1 || n > 12) ? name[0] : name[n];
}


// COMMAND-LINE ARGUMENTS
// Note: argv[0] is the name by which the program was invoked.
int main(int argc, char *argv[])
{
    for (int y = 2019; y < 2026; ++y)
        printf("%d %d\n", y, day_of_year(y, 3, 1));     // display results for Mar 1st of each year

<<<<<<< HEAD
    // VOID POINTERS
    float g = 3.14;
    void *vptr=&g;
    float f = *(float *)vptr;
    printf("%f\n", f);

    
=======
    printf("%s\n", month_name(3));

    // Display command-line arguments (if any exist)
    for (int i = 1; i < argc; ++i)
        printf("%s%s", argv[i], i < argc ? " " : "");
    printf("\n");

    // Display command-line arguments (2nd version)
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");

    return 0;
>>>>>>> 2736ff45e116e36411c0968664c243fd23c91270
}

