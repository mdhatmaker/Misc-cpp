// Classes
#include <iostream>

using namespace std;

// CONCRETE TYPES (vector, string, complex, etc.)
/* The defining characteristic of a concrete type is that its representation is part of its definition.
   That allows implementations to be optimally efficient in time and space. In particular, we can:
   - place objects of concrete types on the static, in statically allocated memory, and in other objects
   - refer to objects directly (and not just through pointers or references)
   - initialize objects immediately and completely (e.g. using constructors)
   - copy and move objects */

// ARITHMETIC TYPE
/* The "classical user-defined arithmetic type" is complex. */
class complex {
    double re, im;      // representation: two doubles
public:
    complex(double r, double i) :re{r}, im{i} {}    // construct complex from two scalars
    complex(double r) :re{r}, im{0} {}              // construct complex from one scalar
    complex() :re{0}, im{0} {}                      // default complex: {0,0}

    double real() const { return re; }              // const specifier indicates function does not modify the object for which it's called
    void real(double d) { re=d; }
    double imag() const { return im; }
    void imag(double d) { im=d; }

    complex& operator+=(complex z)
    {
        re+=z.re;               // add to re and im
        im+=z.im;
        return *this;           // and return the result
    }

    complex& operator-=(complex z)
    {
        re-=z.re;
        im-=z.im;
        return *this;
    }

    complex& operator*=(complex);                   // defined out-of-class somewhere
    complex& operator/=(complex);                   // defined out-of-class somewhere
};

complex& complex::operator*=(complex z)
{
    re*=z.re;
    im*=z.im;
    return *this;
}

complex& complex::operator/=(complex z)
{
    re/=z.re;
    im/=z.im;
    return *this;
}

/* Many useful operations do not require direct access to the representation of complex, so they
   can be defined separately from the class definition. */
complex operator+(complex a, complex b) { return a+=b; }
complex operator-(complex a, complex b) { return a-=b; }
complex operator-(complex a) { return {-a.real(), -a.imag()}; } // unary minus
complex operator*(complex a, complex b) { return a*=b; }
complex operator/(complex a, complex b) { return a/=b; }
bool operator==(complex a, complex b)   // equal
{
    return a.real()==b.real() && a.imag()==b.imag();
}
bool operator !=(complex a, complex b)  // not equal
{
    return !(a==b);
}
complex sqrt(complex);                              // the definition is elsewhere

void f(complex z)       // examples of using Class complex
{
    complex a {2.3};            // construct {2.3,0.0} from 2.3
    complex b {1/a};
    complex c {a+z*complex{1,2.3}};
    // ...
    if (c != b)
        c = -(b/a)+2*b;
}


int main() {

    complex z = {1,0};
    const complex cz {1,3};
    z = cz;                     // OK: assigning to a non-const variable
    //cz = z;                     // error: complex::operator=() is a non-const member function
    double x = z.real();        // OK: complex::real() is a const member function

    return 0;
}



