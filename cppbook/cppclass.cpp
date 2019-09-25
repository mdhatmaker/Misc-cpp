#include <iostream>

using namespace std;

/*
C++ supports several different styles of inheritance:
 Single Inheritance              C:A
 Multiple Inheritance            D:A,B
 Hierarchical Inheritance        E:A, F:A, G:A, ...
 Multilevel Inheritance          C:A, H:C, I:H
 Hybrid (Virtual) Inheritance    E:A, F:A, J:E,F
*/

class Cube
{
public:
    int side;
    int getVolume() {
        return side*side*side;
    }
};

class Animal {
public:
    int legs = 4;
    Animal() {
        cout << "base Animal constructor\n";
    }
};

class Pet {
public:
    string name;
    Pet() {
        cout << "base Pet constructor\n";
    }
    Pet(string xname) {
        cout << "Parameterized base Pet constructor\n";
        name = xname;
    }
};

// Single Inheritance
class Wolf: public Animal {
public:
    int tail = 1;
    Wolf() {
        cout << "derived Wolf constructor\n";
    }
};

// Multiple Inheritance
class Dog: public Animal, public Pet {
public:
    int tail = 1;
    bool stray = false;
    Dog() {
        cout << "derived Dog constructor\n";
    }
    Dog(string xname):Pet(xname) {
        cout << "Parameterized derived Dog constructor\n";
    }
};



int main()
{
    Cube c;
    c.side = 4;
    cout << "volume: " << c.getVolume() << "\n";

    Wolf w;
    cout << w.legs << "\n";
    cout << w.tail << "\n";

    Dog d;
    d.name = "Fido";
    cout << d.legs << " " << d.name << "\n";

    Dog d2("Rex");
    cout << d2.legs << " " << d2.name << "\n";

}