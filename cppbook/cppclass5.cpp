#include <iostream>

using namespace std;

/* Abstract Class and Pure Virtual Function
Abstract Class is a class which contains at least one Pure Virtual function.
An Abstract Class is used to provide an interface for its sub classes.
Classes inheriting an Abstract Class must provide definition to the pure virtual
function, otherwise they will also become an Abstract Class.*/

/* Characteristics of Abstract Class
Abstract Class cannot be instantiated, but pointers and references of Abstract Class
type can be created.
Abstract Class can have normal functions and variables along with a Pure Virtual function.
Abstract Class is mainly used for Upcasting so that its derived classes can use its interface.
Classes inheriting an Abstract Class must implement all Pure Virtual functions or else
they will become Abstract too.*/

/* Pure Virtual Functions
Pure Virtual functions are virtual functions with no definition. They start
with virtual keyword and end with "= 0".*/
class Base {
public:
    virtual void f() = 0;   // Pure Virtual function
};

/* Pure Virtual Definitions
Pure Virtual functions can be given a small definition in the Abstract class,
which you want all the derived classes to have. Still you cannot create an object
of the Abstract class.
Also, the Pure Virtual function must be defined outside the class definition.
Attempting to define it inside the the class definition (inline definition) is illegal
and will result in a compiler error.*/
void Base::f() {    // Pure Virtual definition
    cout << "Pure Virtual definition\n";
}

class Derived:public Base {
public:
    void f() {
        cout << "Implementation of Virtual Function in Derived class\n";
    }
};


int main()
{
    //Base obj;       // ERROR: Compile-time Error instantiating Abstract Class
    Base* b;        // Base class pointer
    Derived d;      // Derived class object
    b = &d;
    b->f();
}