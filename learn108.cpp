// operators: arithmetic, comparison, logical

#include <iostream> 

using namespace std;

int main()
{
    int x = 5, y = 6;

    // ARITHMETIC
    int z;
    z = x+y;    // plus
    z = +x;     // unary plus
    z = x-y;    // minus
    z = -x;     // unary minus
    z = x*y;    // multiply
    z = x/y;    // divide
    z = x%y;    // remainder (modulus) for integers”

    // In addition to the conventional arithmetic and logical operators,
    // C++ offers more specific operations for modifying a variable:
    x+=y;       // x = x+y
    ++x;        // increment: x = x+1
    x-=y;       // x = x-y
    --x;        // decrement: x = x-1
    x*=y;       // scaling: x = x*y
    x/=y;       // scaling: x = x/y
    x%=y;       // x = x%y

    // COMPARISON
    bool b;
    b = x==y;  // equal
    b = x!=y;  // not equal
    b = x<y;   // less than
    b = x>y;   // greater than
    b = x<=y;  // less than or equal
    b = x>=y;  // greater than or equal”

    // LOGICAL
    int bitwise;
    bool logical;
    bitwise = x&y;      // bitwise and
    bitwise = x|y;      // bitwise or
    bitwise = x^y;      // bitwise exclusive or
    bitwise = ~x;       // bitwise complement
    logical = x&&y;     // logical and
    logical = x||y;     // logical or
    logical = !x;       // logical not (negation)


    string tf = logical ? "true" : "false";     // tertiary operator

    cout << "last z value: " << z << endl;
    cout << "last b value: " << b << endl;
    cout << "last bitwise value: " << bitwise << endl;
    cout << "last logical value: " << tf << endl;
}