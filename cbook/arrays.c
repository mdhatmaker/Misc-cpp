#include <stdio.h>
#include <stdlib.h>

#define LENGTH  5

void copy(char to[], char from[]);

int main() {

    char line1[LENGTH];
    char line2[LENGTH];

    line1[0] = 'z';
    printf("'%s' '%s'\n", line1, line2);
    copy(line2, line1);
    printf("'%s' '%s'\n", line1, line2);

}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}