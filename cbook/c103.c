#include <stdio.h>

/* Variable Types, Constants, and Enumerations */

#define VTAB_OCT '\013'     // ASCII vertical tab
#define BELL_OCT '\007'     // ASCII bell character
#define VTAB_HEX '\xb'      // ASCII vertical tab
#define BELL_HEX '\x7'      // ASCII bell character

// Relevant escape sequence characters:
// \b   backspace
// \n   newline
// \r   carriage return
// \t   horizontal tab
// \v   vertial tab
// \\   backslash
// \?   question mark
// \'   single quote
// \"   double quote
// \ooo octal number
// \xhh hexadecimal number

// There is one other kind of constant, the enumeration constant.
// An enumeration is a list of constant integer values.
// The first name in an enum has value 0, the next 1, and so on,
// unless explicit values are specified.
// Names in different enumerations must be distinct.
// Values need not be distinct in the same enumeration.
enum boolean { NO, YES };
// In the following, FEB=2, MAR=3, etc...
enum months { JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main()
{
    int i1;
    short i2;       // short int ("int" can be omitted)
    long i3;        // long int ("int" can be omitted)
    float d1;
    double d2;
    char ch;
    int* p;

    printf("int i1    %lu\n", sizeof(i1));
    printf("short i2  %lu\n", sizeof(i2));
    printf("long i3   %lu\n", sizeof(i3));
    printf("float d1  %lu\n", sizeof(d1));
    printf("double d2 %lu\n", sizeof(d2));
    printf("char ch   %lu\n", sizeof(ch));
    printf("int* p    %lu\n", sizeof(p));

    // CONSTANTS
    long xl = 123456789L;           // terminal L for long constant
    unsigned xu = 53u;              // terminal U for unsigned constant
    unsigned long xul = 98765ul;    // terminal UL for unsigned long constant

    double xd1 = 123.4;             // (double) floating-point constant
    double xd2 = 1e-2f;             // (double) floating-point constant
    float xf1 = 123.4f;             // floating-point constant
    float xf2 = 1e-2f;              // floating-point constant
    int xo = 0123;                  // leading 0 (zero) for octal constant
    int xh = 0xFA73B96E;            // leading 0x for hexadecimal constant
    
    long xol = 011L;                // long constant with value 9 decimal
    unsigned long xhul = 0xFUL;     // unsigned long constant with value 15 decimal

    char xc = 'z';                  // character constant (numeric value of char like '0' == 48)

}