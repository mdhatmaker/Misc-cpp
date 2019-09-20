// Scope and Lifetime
#include <iostream>
#include <vector>

using namespace std;


// Local scope
// Class scope
// Namespace scope

vector<int> vec;        // vec is global (a global vector of integers)

struct Record {
    string name;        // name is a member of Record (a string member)
};

void fct(int arg)       // fct is global (a global function), arg is local (an integer argument)
{
    string motto {"Who dares wins"};    // motto is local
    auto p = new Record{"Hume"};        // p points to an unnamed Record (created by new)
}

int main() {

    return 0;
}