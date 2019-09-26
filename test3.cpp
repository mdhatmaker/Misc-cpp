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
char** split_string(char*);

int parse_int(char*);


int* getUnallottedUsers(int bids_rows, int bids_columns, int** bids, int totalShares, int* result_count) {
    int max=0, min=INT_MAX;
    for (int i=0; i<bids_rows; ++i)
    {
        int id = *bids[i*4];
        int shares = *bids[i*4+1];
        int price = *bids[i*4+2];
        int timestamp = *bids[i*4+3];

        if (price > max) max = price;
        if (price < min) min = price;
    }

    printf("%d %d\n", min, max);

}

// end of bidding window:
// all available shares have been allotted OR
// all bidders have received the shares they bid for
// (whichever comes earlier)

// bid: <user Id, number of shares, bidding price, timestamp>

// 1. bidder with highest price gets number they bid for
// 2. if multiple bidders have bid at same price:
//      each bidder in same price group get s 1 share each consecutively (bidders arranged by timestamp).
//      Once a bidder gets the number of shares they bid for, they will be removed from above iterative process

int main()
{
    /*char* line;
    
    line = readline();          // int n - size of the array bids
    int nr = parse_int(line);
    line = readline();          // # of attributes for each bid
    int nc = parse_int(line);
    printf("%d %d \n", nr, nc);

    int bids[nr * nc];

    for (int i=0; i<nr; ++i)
    {
        line = readline();
        char** s = split_string(line);

        int i1 = atoi(s[0]);
        int i2 = atoi(s[1]);

        printf("%d %d \n", i1, i2);
    }

    line = readline();
    int totalShares = parse_int(line);
    printf("%d \n", totalShares);*/

    /*int r = 4;
    int c = 4;
    int bids[r*c];
    bids[0] = 1;
    bids[1] = 2;*/

}

