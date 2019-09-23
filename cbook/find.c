#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int xgetline(char *line, int max);

/* Pointers and Arrays */

// COMMAND-LINE ARGUMENTS (continued)
// Note: argv[0] is the name by which the program was invoked.
/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2) {
        printf("Usage: find pattern\n");
    }
    else {
        while (xgetline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
        printf("\nFound: %d matches\n", found);
    }

    return found;
}

int xgetline(char s[], int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}