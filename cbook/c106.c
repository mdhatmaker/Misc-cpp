#include <stdio.h>

/* Strings */

/* strlen: return length of s */
int stringlen(char s[])
{
    int i;

    while (s[i] != '\0')
        ++i;
    return i;
}

int main()
{
    char* hello = "hello world!\n";

    printf("%d\n", stringlen(hello));
    
}