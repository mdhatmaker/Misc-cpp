#include <iostream>
#include <typeinfo>     // for 'typeid' to work

using namespace std;

/* Polymorphism and Function Overriding in Inheritance
Polymorphism means having multiple forms of one thing. In inheritance, polymorphism
is done by method overriding when both Base and Derived class have member function
with same declaration but different definition.

If we inherit a class and provide a definition for a base class's function again
inside the derived class, then that function is said to be overridden, and this
mechanism is called Function Overriding.
*/
class Base {
public:
    void show() {   // overridden function must have exactly the same declaration in both base and derived class
        cout << "Base class\n";
    }
};

class Derived:public Base {
public:
    void show() {   // "same declaration" means same name, same return type, and same parameter list
        cout << "Derived class\n";
    }
};

/* Function Call Binding with Class Objects
Connecting the function call to the function body is called Binding. When it
is done before the program is run, it is called Early Binding (or Static Binding
or Compile-time Binding).*/


int main()
{
    Base b;         // Base class object
    Derived d;      // Derived class object
    b.show();       // Early Binding occurs
    d.show();       // Early Binding occurs
    cout << "\n";

    Base* b2;       // Base class pointer
    Derived d2;     // Derived class object
    b2 = &d2;
    b2->show();     // Early Binding occurs (although object is of Derived class, Base class's method is still called)

    /* On seeing Base class's pointer, compiler set call to Base class's show()
     function, ignoring the actual object type. */
}