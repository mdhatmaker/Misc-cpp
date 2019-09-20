#include <iostream>

using namespace std;

int main() {
    int a[7];
    std::cout << "Length of array = " << (sizeof(a)/sizeof(*a)) << std::endl;

    return 0;
}