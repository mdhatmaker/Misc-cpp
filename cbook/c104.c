#include <stdio.h>

/* Formatting printf Output */

// SYMBOLIC CONSTANTS
#define MY_CONSTANT     10001
#define MIN             -999
#define MAX             999
#define PI              3.14159

int main()
{
    int i1 = 23;                // integer
    long i2 = 1999;             // long integer
    unsigned int i3 = 7;        // non-negative integer
    unsigned long i4 = 2048;    // non-negative long integer
    float d1 = 1.75;            // floating point value
    double d2 = 3.1415926;      // double-precision floating point value
    char ch = 'a';              // character
    int* p = &i1;               // pointer to integer (& for "address of")
    char* s = "howdy";          // string of characters

    printf("%%d    :%d\n", i1);             // display an integer value
    printf("%%6d   :%6d\n", i1);
    printf("%%o    :%o\n", i1);             // display an octal
    printf("%%x    :%x\n", i1);             // display a hexadecimal
    printf("%%f    :%f\n", d1);             // display a floating point value
    printf("%%6f   :%6f\n", d1);
    printf("%%.2f  :%.2f\n", d1);
    printf("%%6.2f :%6.2f\n", d1);
    printf("%%s    :%s\n\n", s);            // display a string

    printf("%d\n", *p);                     // display an int (* to dereference pointer)
    printf("%d\n", MY_CONSTANT);            // display a constant int value
    printf("%f\n", PI);                     // display a constant float value
    printf("%lu\n", (unsigned long)p);      // display a pointer value (cast to unsigned long)

}