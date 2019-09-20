// Assignment and Initialization
#include <iostream>

using namespace std;


int main() {

    int x = 2;
    int y = 3;
    x = y;                  // Two objects assigned with "=" are independent (x and y are separate in memory).
                            // Unlike Java, C#, and other languages, but like C, this is true for all types.

    int* p = &x;
    int* q = &y;            // now p!=q and *p!=*q
    p = q;                  // p becomes &y; now p==q (and *p==*q)
    

    int z = 7;
    int& r {z};             // bind r to x (r refers to x)
    //int& r = z;             // bind r to x (r refers to x)
    cout << z << endl;      // z has original value (7)
    r = 8;                  // update z (referenced by r) to hold value of 8
    cout << z << endl;
    //int& r2;                // error: uninitialized reference
    //r2 = 99;                // assign to whatever r2 refers to

    return 0;
}