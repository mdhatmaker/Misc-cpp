// strings

#include <iostream> 
#include <string>

using namespace std;

double get(const vector<double>& vec, int index);     // type: double(const vector<double>&,int)”

// A function can be the member of a class. For such a member function,
// the name of its class is also part of the function type:
//char& String::operator[](int index);    // type: char& String::(int)

int main()
{
    std::string str ("Test string");
    for (int i=0; i<str.length(); ++i)
    {
        std::cout << str[i];
    }
    return 0;   // you can explicitly state the return value of zero from main, but it's not necessary
}