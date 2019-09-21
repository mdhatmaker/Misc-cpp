/*
 * C program to compute the value of X ^ N given X and N as inputs
 */
#include <stdio.h>
#include <math.h>
 
long int power(int x, int n);
 
int main()
{
    long int x, n, xpown;
 
    printf("Enter the values of X and N \n");
    scanf("%ld %ld", &x, &n);
    
    xpown = power(x, n);
    printf("X to the power N = %ld\n", xpown);
}

/*  Recursive function to computer the X to power N */
long int power(int x, int n)
{
    if (n == 1)
        return(x);
    else if (n % 2 == 0)
        /*  if n is even */
        return (pow(power(x, n/2), 2));
    else
        /*  if n is odd */
        return (x * power(x, n - 1));
}