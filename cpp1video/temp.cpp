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

char* findNumber(int arr_count, int* arr, int k) {
    for (int i=0; i<arr_count; ++i) {
        if (arr[i] == k)
            return (char*)"YES";
    }
    return (char*)"NO";
}

int* oddNumbers(int l, int r, int* result_count) {
    if (l%2==1 || r%2==1)
        *result_count = (r-l)/2+1;
    else
        *result_count = (r-l)/2;

    int *a = (int*)malloc(*result_count * sizeof(int));

    int i = 0;
    for (int k=l; k<=r; ++k) {
        if (k%2 == 1)
            *(a+i++) = k;
    }
    return a;
}

int main() {

    int result_count;
    int* odds = oddNumbers(3, 9, &result_count);
    cout << "result count: " << result_count << "\n";
    for (int i=0; i<result_count; ++i)
    {
        cout << *(odds+i) << " ";
    }
    cout << "\n";
    return 0;

    int arr[5] = {1,2,3,4,5};
    char* res = findNumber(5, arr, 1);
    cout << res << "\n";
    return 0;

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