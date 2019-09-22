#include <stdio.h>

/* Pointers and Arrays */

// POINTERS AND ADDRESSES
char ch;
char* pch = &ch;            // the unary & operator gives the address of an object

// POINTERS AND FUNCTION ARGUMENTS
void swap(int *px, int *py)     /* interchange *px and *py */
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

// POINTERS AND ARRAYS - Any operation that can be achieved by array subscripting can be done with pointers.
/* When an array name is passed to a function, what is passed is the location of the initial element.
   As formal parameters in a function definition, "char s[]" and "char *s" are equivalent (although the latter
   more clearly indicates the variable is a pointer).*/
/* xstrlen: return length of string s */
int xstrlen(char *s)
{
    int n;
    for (n=0; *s != '\0'; s++)
        n++;
    return n;
}

void f(int *a)
{
    printf("int: %d\n", *a);
}

int main()
{
    int x=1, y=2, z[10];
    int *ip;                // ip is a pointer to int
    ip = &x;                // ip now points to x
    y = *ip;                // y is now 1
    *ip = 0;                // x is now 0
    ip = &z[0];             // ip now points to z[0]

    ip = &x;                // ip again points to x
    *ip = *ip + 10;         // *ip can occur in any context where x could occur
    (*ip)++;                // parentheses are used with the ++ (increment) operator to avoid incrementing the pointer itself

    printf("%d %d\n",x,y);
    swap(&x, &y);           // pass the pointers to x and y using the & ("address of") operator
    printf("%d %d\n",x,y);

    int a[10];
    int *pa;
    pa = &a[0];             // sets pa to point to element zero of a (pa contains address of a[0])
    *(pa+1) = 4;            // *(pa+1) refers to the contents of a[1]
    printf("%d\n", a[1]);
    pa = a;                 // equivalent to pa=&a[0]

    f(&a[1]);
    f(a+1);                 // equivalent to the function call above
        
    printf("%d\n", xstrlen("hello"));

}

