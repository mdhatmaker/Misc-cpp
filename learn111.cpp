// variable scope and lifetime

#include <iostream> 
#include <vector>

using namespace std;

/*
    A declaration introduces its name into a scope:

    Local scope: A name declared in a function or lambda is called a local name.
        Its scope extends from its point of declaration to the end of the block in which its declaration occurs.
        A block is delimited by a { } pair. Function argument names are considered local names.
    Class scope: A name is called a member name (or a class member name) if it is defined in a class, outside any function,
        lambda, or enum class. Its scope extends from the opening { of its enclosing declaration to the end of that declaration.
    Namespace scope: A name is called a namespace member name if it is defined in a namespace outside any function, lambda,
        class, or enum class. Its scope extends from the point of declaration to the end of its namespace.
    
    A name not declared inside any other construct is called a global name and is said to be in the global namespace.
*/

vector<int> vec;    // vec is global (a global vector of integers)

struct Record {
     string name;   // name is a member or Record (a string member)
     // ...
};

void fct(int arg)   // fct is global (a global function)
                    // arg is local (an integer argument)
{
     string motto {"Who dares wins"};  // motto is local
     auto p = new Record{"Hume"};      // p points to an unnamed Record (created by new)
     // ...
}

int main()
{
    cout << "output: learn111" << endl;
}