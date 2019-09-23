#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Pointers and Arrays */

#define MAXLINES 5000       // max #lines to be sorted
char *lineptr[MAXLINES];    // pointers to text lines

/*int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);*/

// POINTERS TO FUNCTIONS

int numcomp(char *, char *);
int strcomp(char *, char *);
void swap(void *v[], int, int);
// Sort using the function passed
void xqsort(void *v[], int left, int right, int (*comp)(void *, void *));

int add(int x, int y) { return x+y; }
int sub(int x, int y) { return x-y; }
// Use the function passed to get the result
int f(int x, int y, int (*op)(int, int))
{
    return (*op)(x, y);
}


int main(int argc, char *argv[])
{
    int numeric;
    printf("\n");

    numeric = 0;
    lineptr[0] = "dffs";
    lineptr[1] = "sfalj";
    lineptr[2] = "zfjhf";
    lineptr[3] = "adfo";
    lineptr[4] = "joiewf";
    lineptr[5] = "wedsa";
    xqsort(lineptr, 0, 5, (int (*)(void*,void*))(numeric ? numcomp : strcomp) );
    for (int i=0; i<6; ++i)
        printf("%s%s\n", lineptr[i], i==5 ? "\n" : "");

    numeric = 1;
    lineptr[0] = "5387";
    lineptr[1] = "1583";
    lineptr[2] = "2638";
    lineptr[3] = "3958";
    lineptr[4] = "1023";
    lineptr[5] = "1001";
    xqsort(lineptr, 0, 5, (int (*)(void*,void*))(numeric ? numcomp : strcomp) );
    for (int i=0; i<6; ++i)
        printf("%s%s\n", lineptr[i], i==5 ? "\n" : "");



    int res;
    // pass the add function
    res = f( 5, 2, (int (*)(int,int))(add) );
    printf("%d\n", res);
    // pass the sub function
    res = f( 5, 2, (int (*)(int,int))(sub) );
    printf("%d\n", res);

}


/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int numcomp(char *s, char *t) {
    double v1, v2;
    v1 = atof(s);
    v2 = atof(t);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcomp(char *s, char *t) {
    int i;
    for (i=0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* qsort: sort v[left]...v[right] into increasing order */
void xqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)      // do nothing if array contains
        return;             // ...fewer than two elements

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    xqsort(v, left, last-1, comp);
    xqsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
