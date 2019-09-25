#include <iostream>
#include <typeinfo>     // for 'typeid' to work

using namespace std;

/* Upcasting and Downcasting
Upcasting is using the Super class's reference or pointer to refer to a
Sub class's object.
 Derived -> Base is Upcasting

Downcasting is the opposite of Upcasting, in which we convert Super
class's reference or pointer into derived class's reference or pointer.
 Base -> Derived is Downcasting
*/

class Super {
    int x;
public:
    void funBase() {
        cout << "Super function\n";
    }
};

class Sub:public Super {
    int y;
};

/* Functions That Are Never Inherited
Constructors and Destructors are never inherited and hence never overrided.
Assignment operator (=) is never inherited. It can be overloaded but can't be
inherited by sub class.
*/

/* Inheritance and Static Functions
Static functions are inherited into the derived class.
If you redefine a static in derived class, all the other overloaded functions
in base class are hidden.
Static member functions can never be virtual.
*/

/* Hybrid Inheritance and Virtual Class
In Multiple Inheritance, the derived class inherits from more than one base
class. Hence, in Multiple Inheritance there are many chances of ambiguity.
*/
class A {
    public:
    A() {
        cout << "class A constructor\n";
    }
    void show() {
        cout << "A::show() function called\n";
    }
};

/* ERROR: ambiguous choice of which show() function to call
class B:public A {
    // class definition
};

class C:public A {
    // class definition
};

The virtual keyword tells compiler to call any of two show() functions in D below
*/

class B:virtual public A {
public:
    B() {
        cout << "class B constructor\n";
    }
};

class C:virtual public A {  // virtual keyword tells compiler to call any of two show() functions in D below
public:
    C() {
        cout << "class C constructor\n";
    }
};

/* In this case both class B and C inherit function show() from class A.
Hence, class D has two inherited copies of function show(). In main() function
when we call function show(), ambiguity arises because compiler doesn't know
which show() function to call.
We fixed this by using the virtual keyword while inheriting. */
class D:public B, public C {
public:
    D() {
        cout << "class D constructor\n";
    }
};



int main()
{
    Super* ptr;         // Super class pointer
    Sub obj;
    ptr = &obj;         // "Upcasting"
    cout << "ptr " << typeid(ptr).name() << "\n";
    cout << "obj " << typeid(obj).name() << "\n";
    ptr->funBase();

    Super &ref{obj};    // Super class's reference
    Sub obj2;
    ref = obj2;         // "Upcasting"
    cout << "ref " << typeid(ref).name() << "\n";
    ref.funBase();
    cout << "\n";


    /* A single instance of virtual base class A is shared by multiple classes
    that inherit from it (B and C), hence constructor of base class A is only
    called once by the constructor of concrete class D. */
    D objd;
    objd.show();    // the virtual keyword tells compiler to call any of the two show() functions

}