#include <stdio.h>

/* Pointers and Arrays */

#define ALLOCSIZE 10000     /* size of available space */

// ADDRESS ARITHMETIC
static char allocbuf[ALLOCSIZE];    // storage for alloc
static char *allocp = allocbuf;     // next free position

char *alloc(int n)      /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   // it fits
        allocp += n;
        return allocp - n;  // old p        
    }
    else {                                      // not enough room
        return 0;
    }
}

void afree(char *p)     /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int xstrlen(char *s)    /* xstrlen: return length of string s */
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;       // pointer subtraction is also valid
}

void xstrcpy(char *s, char *t)  /* xstrcpy: copy t to s; array subscript version */
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void ystrcpy(char *s, char *t)  /* zstrcpy: copy t to s; pointer version */
{
    int i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void zstrcpy(char *s, char *t)  /* zstrcpy: copy t to s; pointer version (condensed) */
{
    while (*s++ = *t++) // note that we don't even need to compare to 0 because the result will BE zero
        ;
}

// CHARACTER POINTERS AND FUNCTIONS
char *pmessage;

int main()
{
    printf("%d\n", xstrlen("howdy"));       // test our xstrlen function to get string length

    pmessage = "now is the time";           // assigns to pmessage a pointer to the character array

    char amsg[] = "now is the time";        // an array - individual characters within the array may be changed
    char *pmsg = "now is the time";         // a pointer - points to a string constant; result is undefined if you try to modify string contents

    char *srcmsg1 = "this is our message";
    char *srcmsg2 = "this is her message";
    char *srcmsg3 = "this is his message";  // we'll make it wasy by keeping the source strings the same size
    char destmsg[xstrlen(srcmsg1)];

    xstrcpy(destmsg, srcmsg1);
    printf("%s\n", destmsg);
    ystrcpy(destmsg, srcmsg2);
    printf("%s\n", destmsg);
    zstrcpy(destmsg, srcmsg3);
    printf("%s\n", destmsg);
    
    int a[10];
    int *p = a;
    int val = 23;
    *p++ = val;                             // push val onto stack
    val = 0;                                // clear val to zero
    val = *--p;                             // pop top of stack into val
    printf("%d\n", val);                    // val should hold the same value we previously pushed onto the stack
    

}

