#include <iostream>

using namespace std;

/* Operator Overloading
Operator overloading is a type of polymorphism in which an operator is overloaded to
give user-defined meaning to the operator. Overloaded operator is used to perform operation
on user-defined type. For example '+' operator can be overloaded to perform addition on
various data types.

Almost any operator can be overloaded, but a few cannot:
 scope operator (::)
 sizeof
 member selector (.)
 member pointer selector (*)
 ternary operator (?:)

Operator Overloading Syntax
 ReturnType ClassName::Operator OperatorSymbol(argument list)
 {
     // function body
 }

 Operator overloading can be implemented in a Member Function, Non-Member Function,
 or Friend Function.
 
 Operator overloading function can be Member Function if the Left operand is an object
 of that class. But if the Left operand is different, then operator overloading function
 must be a Non-Member Function.

 Operator overloading function can be made Friend Function if it needs access to the private
 and protected members of class.
*/

/* Restrictions on Operator Overloading */


class Time {
    int h,m,s;
public:
    Time() {
        h=0, m=0, s=0;
    }
    void setTime(int,int,int);
    void show() {
        cout << h << ":" << m << ":" << s << "\n";
    }

    Time operator+(Time);       // overloading '+' operator
};

Time Time::operator+(Time t1) { // operator function
    Time t;
    int a,b;
    a = s+t1.s;
    t.s = a%60;
    b = (a/60)+m+t1.m;
    t.m = b%60;
    t.h = (b/60)+h+t1.h;
    t.h = t.h%12;
    return t;
}

void Time::setTime(int xh, int xm, int xs) {
    h = xh;
    m = xm;
    s = xs;
}


int main()
{
    Time t1,t2,t3;

    t1.setTime(11,11,15);       // first time
    t2.setTime(11,23,30);       // second time
    t3 = t1+t2;                 // add to get the third time
    t1.show();
    t2.show();
    t3.show();
    cout << "\n";

    
}