#include <iostream>

using namespace std;

double square(double x)     // function returns square of (double) number
{
    return x*x;
}

void print_square(double x)     // function to display number and its square
{
    cout << "the square of " << x << " is " << square(x) << "\n";  // can use special chars like '\n' for newline
}

int main()
{
    print_square(1.234);    // call function

    return 0;   // you can explicitly state the return value of zero from main, but it's not necessary
}