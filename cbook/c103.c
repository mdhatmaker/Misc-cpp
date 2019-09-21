#include <stdio.h>

/* Variable Types */

int main()
{
    int i1;
    long i2;
    float d1;
    double d2;
    char ch;
    int* p;

    printf("int i1    %lu\n", sizeof(i1));
    printf("long i2   %lu\n", sizeof(i2));
    printf("float d1  %lu\n", sizeof(d1));
    printf("double d2 %lu\n", sizeof(d2));
    printf("char ch   %lu\n", sizeof(ch));
    printf("int* p    %lu\n", sizeof(p));

}