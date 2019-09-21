#include <iostream> 

using namespace std;

double add2(double d1, double d2)
{
    return d1 + d2;
}

int add2(int i1, int i2)    // an overloaded function has the same name but different argument count/types
{
    return i1 + i2;
}

void print_it(double d)
{
    cout << "the double result is " << d << endl;
}

void print_it(int i)    // an overloaded function has the same name but different argument count/types
{
    cout << "the int result is " << i << endl;
}

int main()
{
    double d;
    d = add2(3.2, 4.3);
    print_it(d);

    int i = add2(3, 4);     // you can declare a variable type and assign it in a single statement
    print_it(i);
}