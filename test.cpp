#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

long parse_long(char*);


char* getSpreadsheetNotation(long n)
{
    int perRow = 702;

    int r = n / perRow + 1;
    int c = n % perRow;

    char a1 = 'A' + (c / 26) - 1;
    char a2 = 'A' + (c % 26) - 1;

    char* s = (char*) malloc(16 * sizeof(char));

    if (a2 < 'A') {
        sprintf(s, "%dZZ", r-1);
    }
    else if (a1 < 'A') {
        sprintf(s, "%d%c", r, a2);
    }
    else {
        sprintf(s, "%d%c%c", r, a1, a2);
    }
    
    return s;
}

int main()
{
    char* s;

    s = getSpreadsheetNotation(27);
    printf("%s\n", s);
    s = getSpreadsheetNotation(703);
    printf("%s\n", s);
    s = getSpreadsheetNotation(702);
    printf("%s\n", s);

}

