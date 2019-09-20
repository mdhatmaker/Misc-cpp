// User-Defined Types
#include <iostream>

using namespace std;

// STRUCTURES
struct Vec {
    int sz;                 // number of elements
    double* elem;           // pointer to elements
};

void vec_init(Vec& v, int s)    // initialize a Vec struct of size s
{
     v.elem = new double[s];    // allocate an array of s doubles
     v.sz = s;
}

/* We use . (dot) to access struct members through a name (and through a reference)
   and −> to access struct members through a pointer. */
void f(Vec v, Vec& rv, Vec* pv)
{
     int i1 = v.sz;         // access through name
     int i2 = rv.sz;        // access through reference
     int i3 = pv->sz;       // access through pointer
}

// CLASSES
class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} { }      // construct a Vector by initializing elem and sz
    double& operator[](int i) { return elem[i]; }       // element access: subscripting
    int size() { return sz; }                           // public method to return size (sz)
private:
    double* elem;           // pointer to the elements
    int sz;                 // the number of elements
};

// UNIONS
struct Node {
    int data;               // the data being stored at the node
    Node *next;             // pointer to the next node
};

/* A union is a struct in which all members are allocated at the same address so that the
   the union occupies only as much space as its largest member.
   Naturally, a union can hold a value for only one member at a time. */
enum Type { ptr, num };     // a Type can hold values ptr and num

struct EntryX {
    string name;            // string is a standard-library type
    Type t;
    Node* p;                // use p if t==ptr
    int i;                  // use i if t==num
};

void f(EntryX* pe)
{
    if (pe->t == num)
        cout << pe->i;
}

/* The members p and i are never used at the same time, so space is wasted. It can be
   easily recovered by specifying that both should be members of a union. */
union Value {
    Node* p;
    int i;
};

struct Entry {
    string name;
    Type t;
    Value v;                // use v.p if t==ptr; use v.i if t==num
};

void f(Entry* pe)
{
    if (pe->t == num)
        cout << pe->v.i;
}

/*
// The standard library type, variant, can be used to eliminate most direct uses of unions.
// A variant stores a value of one of a set of alternative types. For example, a
// variant<Node*,int> can hold either a Node* or an int.
// For many uses, a variant is simpler and safer to use than a union.
struct EntryV {
    string name;
    variant<Node*,int> v;
};

void f(EntryV* pe)
{
    if (holds_alternative<int>(pe->v))  // does *pe hold an int?
        cout << get<int>(pe->v);        // get the int
}
*/

// ENUMERATIONS
/* Enumerations are used to represent small sets of integer values.
   By default, an enum class has only assignment, initialization, and comparisons defined. */
enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

/* An enumeration is a user-defined type, we can define operators for it. */
Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
    switch (t) {
        case Traffic_light::green:  return t=Traffic_light::yellow;
        case Traffic_light::yellow: return t=Traffic_light::red;
        case Traffic_light::red:    return t=Traffic_light::green;
    }
}

/* Function template to explicitly convert enum to an integer using a cast.
   used as:  std::cout << as_integer(a) << std::endl; */
template <typename Traffic_light>
auto as_integer(Traffic_light const value)
    -> typename std::underlying_type<Traffic_light>::type
{
    return static_cast<typename std::underlying_type<Traffic_light>::type>(value);
}


int main() {

    Vec vec;    
    vec_init(vec, 5);

    Vector v(6);                        // a Vector with 6 elements


    Color col = Color::red;
    Traffic_light light = Traffic_light::red;
    /*Color x = red;                  // error: which red?
    Color y = Traffic_light::red;   // error: that red is not a Color
    int i = Color::red;             // error: Color::red is not an int
    Color c = 2;                    // initialization error: 2 is not a Color*/

    /*// Initialize an enum with a value from its underlying type (by default that's int) using explicit conversion
    Color x = Color{5};             // OK, but verbose
    Color y {6};                    // also OK*/

    Traffic_light next = ++light;       // next becomes Traffic_light::green
    cout << "next = " << static_cast<std::underlying_type<Traffic_light>::type>(next) << endl;
    cout << "next = " << as_integer(next) << endl;

   /* If you don’t want to explicitly qualify enumerator names and want enumerator values to be ints (without
      the need for an explicit conversion), you can remove the class from enum class to get a "plain" enum.
      The enumerators from a "plain" enum are entered into the same scope as the name of their enum and
      implicitly converts to their integer value. */
    enum ColorX { red, green, blue };
    int colx = green;
    cout << "colx = " << colx << endl;


    return 0;
}



