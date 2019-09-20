#include <iostream>

using namespace std;

int main() {

    int x = 5, y = 2;    
    cout << "x is " << x << endl;
    cout << "y is " << y << endl << endl;

    // arithmetic operators
    cout << "x + y    " << x+y << endl;         // plus
    cout << "+x       " << +x << endl;          // unary plus
    cout << "x - y    " << x-y << endl;         // minus
    cout << "-x       " << -x << endl;          // unary minus
    cout << "x * y    " << x*y << endl;         // multiply
    cout << "x / y    " << x/y << endl;         // divide
    cout << "x % y    " << x%y << endl;         // remainder (modulus) for integers
    cout << endl;

    // comparison operators
    cout << "x == y   " << (x==y) << endl;      // equal
    cout << "x != y   " << (x!=y) << endl;      // not equal
    cout << "x < y    " << (x<y) << endl;       // less than
    cout << "x > y    " << (x>y) << endl;       // greater than
    cout << "x <= y   " << (x<=y) << endl;      // less than or equal
    cout << "x >= y   " << (x>=y) << endl;      // greater than or equal
    cout << endl;

    // logical operators
    cout << "x & y    " << (x&y) << endl;       // bitwise and
    cout << "x | y    " << (x|y) << endl;       // bitwise or
    cout << "x ^ y    " << (x^y) << endl;       // bitwise exclusive or
    cout << "~x       " << (~x) << endl;        // bitwise complement
    cout << "x && y   " << (x&&y) << endl;      // logical and
    cout << "x || y   " << (x||y) << endl;      // logical or
    cout << "!x       " << (!x) << endl;        // logical not (negation)
    cout << endl;

    // operations for modifying variables
    cout << "x += y   " << (x+=y) << endl;      // x = x+y
    cout << "++x      " << (++x) << endl;       // increment: x = x+1
    cout << "x -= y   " << (x-=y) << endl;      // x = x-y
    cout << "--x      " << (--x) << endl;       // decrement: x = x-1
    cout << "x *= y   " << (x*=y) << endl;      // scaling: x = x*y
    cout << "x /= y   " << (x/=y) << endl;      // scaling: x = x/y
    cout << "x %= y   " << (x%=y) << endl;      // x = x%y
    cout << endl;

    return 0;
}