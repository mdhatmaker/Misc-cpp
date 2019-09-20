// Modularity: functions, user-defined types, class hierarchies, and templates
#include <iostream>
#include <cmath>

using namespace std;

// DECLARATIONS
/* At the language level, C++ represents interfaces by declaraionts.
   A declaration specifies all that’s needed to use a function or a type.
   The key point here is that the function bodies, the function definitions, are elsewhere. */
double square(double);              // declaration: the square function takes a double and returns a double

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;                   // elem points to an array of sz doubles
    int sz;
};

// DEFINITIONS
double square(double d)             // definition of square()
{    
    return d*d;
}

Vector::Vector(int s)               // definition of the constructor
    :elem{new double[s]}, sz{s}     // initialize members
{    
}

double& Vector::operator[](int i)   // definition of subscripting
{
    return elem[i];
}

int Vector::size()                  // definition of size()
{
    return sz;
}

int main() {

    cout << "4 squared = " << square(4) << endl;
    cout << "sqrt of 4 = " << sqrt(4) << endl;

    return 0;
}



