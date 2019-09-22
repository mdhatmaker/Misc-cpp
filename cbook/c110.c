#include <stdio.h>
#include <ctype.h>

/* Binary */

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

/* delete_rightmost_bit: delete the lowest-order bit */
int delete_rightmost_bit(unsigned x)
{
    return x &= (x-1);
}

int main()
{
    printf("%d\n", getbits(0xFF, 3, 2));
    printf("%d\n", bitcount(0xF1F1));
    printf("%d\n", delete_rightmost_bit(0xFF));

}