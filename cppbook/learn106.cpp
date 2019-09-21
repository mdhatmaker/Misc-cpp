// value types and reference types

#include <iostream> 

using namespace std;

void add1(int i)    // argument is value type (changes NOT refelected)
{
    i += 1;
}

void add2(int& i)   // argument is reference type (changes reflected)
{
    i += 2;
}

int main()
{
    int i = 3;
    add1(i);
    cout << i << endl;
    add2(i);
    cout << i << endl;
}