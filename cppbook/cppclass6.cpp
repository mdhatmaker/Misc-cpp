#include <iostream>

using namespace std;

/* Virtual Destructors
Destructors in the Base class can be Virtual. Whenever Upcasting is done, Destructors
of the Base class must be made virtual for proper destruction of the object.
NOTE: Constructors are never Virtual, only Destructors can be Virtual.*/

/* Upcasting without Virtual Destructor */ 
class Base {
public:
    ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived:public Base {
public:
    ~Derived() {
        cout << "Derived Destructor\n";
    }
};

/* Upcasting with Virtual Destructor */
class Base2 {
public:
    virtual ~Base2() {
        cout << "Base Destructor\n";
    }
};

class Derived2:public Base2 {
public:
    ~Derived2() {
        cout << "Derived Destructor\n";
    }
};

/* Pure Virtual Destructors
Pure Virtual destructors are legal in C++, but they MUST be defined, which is
against the pure virtual behavior.
The only difference between Virtual and Pure Virtual destructor is that Pure Virtual
destructor will make its Base class Abstract.
There is no requirement to implement Pure Virtual destructors in the derived classes.*/
class Base3 {
public:
    virtual ~Base3() = 0;   // Pure Virtual destructor
};

Base3::~Base3() {   // definition of Pure Virtual destructor
    cout << "Base Destructor\n";
}

class Derived3:public Base3 {
public:
    ~Derived3() {
        cout << "Derived Destructor\n";
    }
};



int main()
{
    Base* b = new Derived;      // Upcasting
    delete b;                   // only Base class destructor called which causes memory leak
    cout << "\n";

    Base2* b2 = new Derived2;   // Upcasting
    delete b2;                  // first Derived class's destructor is called, then Base class's destructor is called
    cout << "\n";

    Base3* b3 = new Derived3;   // Upcasting
    delete b3;                  // first Derived class's destructor is called, then Base class's destructor is called
    cout << "\n";
}