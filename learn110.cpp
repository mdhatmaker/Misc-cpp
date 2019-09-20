// implicit variable typing

#include <iostream> 
#include <cmath>

using namespace std;

int main()
{
    // When defining a variable, you don’t need to state its type
    // explicitly when it can be deduced from the initializer:
    auto b = true;       // a bool
    auto ch = 'x';       // a char
    auto i = 123;        // an int
    auto d = 1.2;        // a double
    auto bb {true};      // bb is a bool

    double y = 9.0;
    auto z = sqrt(y);    // z has the type of whatever sqrt(y) returns
    
    cout << "output: learn110" << endl;
}