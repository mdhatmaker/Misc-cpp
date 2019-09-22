#include <stdio.h>

/* Operators: Arithmetic, Bitwise, Relational, Logical */


int main()
{
    int x = 5, y = 2;
    printf("x is %d\n", x);
    printf("y is %d\n\n", y);

    // ARITHMETIC OPERATORS
    printf("x+y   %d\n", x+y);
    printf("x-y   %d\n", x-y);
    printf("x*y   %d\n", x*y);
    printf("x/y   %d\n", x/y);
    printf("x%%y   %d\n", x%y);
    printf("+x    %d\n", +x);
    printf("-x    %d\n", -x);
    printf("++y   %d\n", ++y);
    printf("--y   %d\n", --y);
    printf("y++   %d\n", y++);
    printf("y--   %d\n\n", y--);

    // maybe add +=, -=, etc. here... "ASSIGNMENT OPERATORS"

    // maybe add ternary (?:) operator?
    
    // BITWISE OPERATORS
    printf("x&y   %d\n", x&y);      // bitwise AND
    printf("x|y   %d\n", x|y);      // bitwise inclusive OR
    printf("x^y   %d\n", x^y);      // bitwise exclusive OR
    printf("x<<y  %d\n", x<<y);     // left shift
    printf("x>>y  %d\n", x>>y);     // right shift
    printf("~x    %d\n\n", ~x);     // one's complement (unary)

    // RELATIONAL OPERATORS
    printf("x<y   %d\n", x<y);
    printf("x<=y  %d\n", x<=y);
    printf("x>y   %d\n", x>y);
    printf("x>=y  %d\n", x>=y);
    printf("x==y  %d\n", x==y);
    printf("x!=y  %d\n\n", x!=y);

    int t = 1, f = 0;
    printf("t is %d\n", t);
    printf("f is %d\n\n", f);

    // LOGICAL OPERATORS
    printf("t&&f  %d\n", t&&f);
    printf("t||f  %d\n", t||f);
    printf("!t    %d\n", !t);
    printf("!f    %d\n", !f);

}