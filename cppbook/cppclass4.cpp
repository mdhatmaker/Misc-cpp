#include <iostream>

using namespace std;

/* Virtual Functions
Virtual Function is a function in base class which is overrided in the derived
class (and which tells the compiler to perform Late Binding on this function).

The virtual keyword is used to make a member function of the base class Virtual. */

/* Late Binding
In Late Binding, function call is resolved at runtime. Hence, the compiler
determines the type of object at runtime, and it then binds the function call.
Late Binding is also called Dynamic Binding or Runtime Binding.
*/
class Base {
public:
    void show() {
        cout << "Base class\n";
    }
};

class Base2 {
public:
    virtual void show() {   // virtual keyword will lead to Late Binding of this method
        cout << "Base class\n";
    }
};

class Derived:public Base {
public:
    void show() {
        cout << "Derived class\n";
    }
};

class Derived2:public Base2 {
public:
    void show() {
        cout << "Derived class\n";
    }
};

/* Using Virtual Keyword and Accessing Private Method of Derived Class
We can call private function of derived class from the base class pointer with the help
of virtual keyword. Compiler checks for access specifier only at compile time. So at
run time when Late Binding occurs, it does not check whether we are calling the
private function or the public function. */
class A {
public:
    virtual void show() {   // once a function is declared as virtual in the base class, it will be virtual in all derived classes
        cout << "Base class\n";
    }
};

class B:public A {
private:
    virtual void show() {
        cout << "Derived class\n";
    }
};


int main()
{
    Base* b1;       // Base class pointer
    Derived d1;     // Derived class object
    b1 = &d1;
    b1->show();     // Early Binding occurs (although object is of Derived class, Base class's method is still called)

    Base2* b2;      // Base class pointer
    Derived2 d2;    // Derived class object
    b2 = &d2;
    b2->show();     // Late Binding occurs
    cout << "\n";


    A* a;           // Base class pointer
    B b;            // Derived class object
    a = &b;
    a->show();      // Late Binding occurs (allows us to call private function)
}