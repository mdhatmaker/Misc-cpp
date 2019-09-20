// Function Arguments and Return Values
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int sum(const vector<int>& v)
{
    int s = 0;
    for (const int i : v)
        s += i;
    return s;
}

// ARGUMENT PASSING
void test(vector<int> v, vector<int>& rv)   // v is passed by value; rv is passed by reference
{
    v[1] = 99;          // modify v (a local variable)
    rv[2] = 66;         // modify whatever rv refers to
}


/* We can specify a default function argument. */
void print(int value, int base=10)              // print value in base "base"
{
    // ...algorithm to display value in indicated base...
}

// VALUE RETURN
class Vector {
public:
    // ...
    double& operator[](int i) { return elem[i]; }   // return reference to ith element
private:
    double* elem;       // elem points to an array of sz
    // ...
};

/*int& bad()
{
    int x;
    // ...
    return x;           // bad: return a reference to the local variable x
}*/

class Matrix {
public:
    // ...
private:
    // ...
};

Matrix operator+(const Matrix& x, const Matrix& y)
{
    Matrix res;
    // ... for all res[i,j], res[i,j] = x[i,j]+y[i,j] ...
    return res;
}

Matrix* add(const Matrix& x, const Matrix& y)   // complicated and error-prone 20th century style
{
    Matrix* p = new Matrix;
    // ... for all *p[i,j], *p[i,j] = x[i,j]+y[i,j] ...
    return p;
}

/* The return type of a function can be deduced from its return value. */
/*auto mul(int i, double d) { return i*d; }       // here, "auto" means "deduce the return type"*/

// STRUCTURED BINDING
struct Entry {
    string name;
    int value;
};

Entry create_entry()
{
    string s = "test";
    int i = 23;
    return {s,i};
}

/* We can decorate auto with const and &. */
/*void incr(map<string,int>& m)       // increment the value of each element of m
{
    for (auto& [key,value] : m)
        ++value;
}*/


int main() {

    vector<int> fib = {1,2,3,5,8,13,21};
    int x = sum(fib);                           // x becomes 53

    test(fib, fib);
    cout << fib[1] << ' ' << fib[2] << '\n';    // prints 2 66

    print(x, 16);                               // hexadecimal
    print(x, 60);                               // sexagesimal (Sumerian)
    print(x);                                   // use the default: decimal

    Matrix m1, m2;
    // ...
    Matrix m3 = m1+m2;                          // no copy (if we give Matrix a move constructor)

    Matrix* m4 = add(m1, m2);                   // example w/ manual memory management: just copy a pointer
    // ...
    delete m4;                                  // easily forgotten

    auto e = create_entry();
    cout << "{ " << e.name << "," << e.value << " }\n";

    // This mechanism for giving local names to members of a class object is called "structured binding".
    /*auto [n,v] = create_entry();                // we can "unpack" an Entry's members into local variables
    cout << "{ " << n << "," << v << "}\n";*/

    /*map<string,int> m;
    // ... fill m ...
    for (const auto [key,value] : m)
        cout << "{" << key << "," << value << "}\n";*/


    return 0;
}



