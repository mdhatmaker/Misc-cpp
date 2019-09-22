#include <stdio.h>
#include <stdlib.h>

int max = 199;

int main() 
{ 
    extern int max;
    printf("%d\n", max);

    
} 