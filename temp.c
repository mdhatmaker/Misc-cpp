#include <stdio.h>

/* print Fahrenheit-Celsis table for fahr = 0, 20, ..., 300 */
main()
{
    printf("hello, world\n");

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}