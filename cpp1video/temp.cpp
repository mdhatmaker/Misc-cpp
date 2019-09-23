#include <iostream>

using namespace std;

int x = 5;

int &f() {
    return x;
}

union abc {
        int x;
        char ch;
    };

typedef struct {
    int x;
    int y;
} coord;

int main() {

    // Get array length (sizeof whole array / sizeof individual element)
    int a[7];
    std::cout << "Length of array = " << (sizeof(a)/sizeof(*a)) << std::endl;

    coord center;
    center.x = 9;
    center.y = 3;
    

    /*union abc {
        int x;
        char ch;
    } var;*/
    abc var;
    var.x = 65;
    cout << var.ch << '\n';

    f() = 10;
    cout << x;

    char c = 255;
    printf("c = %i", c);

    if (c>10) printf("hello");

    printf("1/2 = %f", (float)(1/2));

    printf("%d", 5&2);

    return 0;
}