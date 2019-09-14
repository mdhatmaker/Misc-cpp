// initialization of variables and objects

#include <iostream> 
#include <complex>
#include <vector>

using namespace std;

int main()
{
    double d1 = 2.3;                // initialize d1 to 2.3
    double d2 {2.3};                // initialize d2 to 2.3
    double d3 = {2.3};              // initialize d3 to 2.3 (the = is optional with { ... })
    complex<double> z = 1;          // a complex number with double-precision floating-point scalars
    complex<double> z2 {d1,d2};
    complex<double> z3 = {d1,d2};    // the = is optional with { ... }

    vector<int> v {1,2,3,4,5,6};     // a vector of ints
    
    // The = form is traditional and dates back to C, but if in doubt, use the general {}-list form.
    // If nothing else, it saves you from conversions that lose information:
    int i1 = 7.8;        // i1 becomes 7 (surprise?)
    //int i2 {7.8};        // error: floating-point to integer conversion
    
    // Unfortunately, conversions that lose information, narrowing conversions, such as
    // double to int and int to char, are allowed and implicitly applied.
    // The problems caused by implicit narrowing conversions are a price paid for C compatibility.
}