// variable types

#include <iostream> 

using namespace std;

int main()
{
    // all available variable types:
    int i1 = -5;
    unsigned i2 = 5;
    long i3 = 2882934984939;
    float f1 = 5.0;  
    double f2 = 5.0134840149;
    char ch = 'z';
    bool tf = true;

    // integer literals as binary, hex and octal:
    int i01 = 0b10101010;   // 0b prefix indicates binary (base 2)
    int i02 = 0xBAD1234;    // 0x prefix indicates hexadecimal (base 16)
    int i03 = 0334;         // 0 prefix indicates octal (base 8)

    // TIP: To make long literals more readable for humans, we can
    // use a single quote (') as a digit separator. For example,
    // π is about 3.14159'26535'89793'23846'26433'83279'50288 or
    // if you prefer hexadecimal 0x3.243F'6A88'85A3'08D3.

    // NOTE: cout has a default precision that may only display "5.01348" for our double,
    // but internally, the full precision is stored
    cout << i1 << " " << i2 << " " << i3 << " " << i01 << " " << i02 << " " << i03 << endl;
    cout << f1 << " " << f2 << " " << ch << " " << tf << endl;
}