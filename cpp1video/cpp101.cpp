#include <iostream>
#include <vector>
#include <complex>
#include <typeinfo>

using namespace std;

int main() {

    int i1;                                 // declare typed variable (integer)
    long i2 = 2056;                         // declare typed variable and set initial value (long integer)
    unsigned i3 = 0b1010101010;             // (non-negative integer) - "0b" precedes binary literal
    unsigned int i4 = { 0334 };             // w/ initializer (unsigned integer) - "0" precedes octal literal
    unsigned long i5 { 0xFE1234BD };        // equal sign is optional (unsigned long) - "0x" precedes hexadecimal
    float d1 { 1.628 };                     // (float)
    double d2 = 3e-2;                       // (double) - "e" notation for exponent literal
    bool b = true;                          // (boolean)
    char ch = 'a';                          // (character)

    complex<double> z { d1, d2 };           // passing multiple initialization values
    vector<int> v { 1, 2, 3, 4, 5, 6 };     // ...including sequences of values for types like vector

    const int buf_len = 256;                // constant declaration (evaluated at run time)
    constexpr double pi = 3.14159;          // evaluated at compile time

    auto dd3 = d1 + d2;                                         // auto can infer type
    cout << "implicit typed: " << typeid(dd3).name() << endl;   // display implicit type

    cout << typeid(i1).name() << " " << sizeof(i1) << "    ";   // use typeinfo lib to get type of a variable
    cout << typeid(i2).name() << " " << sizeof(i2) << "    ";   // ...and sizeof displays size in bytes
    cout << typeid(i3).name() << " " << sizeof(i3) << "    ";
    cout << typeid(i4).name() << " " << sizeof(i4) << "    ";
    cout << typeid(d1).name() << " " << sizeof(d1) << "    ";
    cout << typeid(d2).name() << " " << sizeof(d2) << "    ";
    cout << endl;

    return 0;
}