#include <stdio.h>
#include <ctype.h>

/* Type Conversions */


/* Remember: A char is just a small integer, so chars may be
   freely used in arithmetic expressions. */

int myatoi(char s[])
{
    int i, n = 0;
    //for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    for (i = 0; isdigit(s[i]); ++i)    // using ctype.h isdigit function
        n = 10 * n + (s[i] - '0');
    return n;
}

int mylower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main()
{
    printf("%d\n", myatoi("109"));
    printf("%c %c\n", mylower('A'), mylower('z'));

}