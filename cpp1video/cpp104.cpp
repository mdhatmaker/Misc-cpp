// Pointers, Arrays, and References
#include <iostream>
#include <vector>

using namespace std;


void print_ints(int v[], int len)       // print the integers in an int array
{
    for (int i=0; i<len; ++i)
        cout << v[i] << " ";
    cout << endl;
}

void copy_fct()                         // copy all values from one array to another array
{
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];

    print_ints(v1, 10);
    
    for (auto i=0; i!=10; ++i)          // copy elements using this for loop
        v2[i] = v1[i];
    
    print_ints(v2, 10);
}

/*
In a declaration, the unary suffix & means “reference to.” A reference is similar to a pointer,
except that you don’t need to use a prefix * to access the value referred to by the reference.
Also, a reference cannot be made to refer to a different object after its initialization.
*/

void increment()                        // increment every value in an array
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};    // array size can be determined by the initializer list

    print_ints(v, 10);

    for (auto& x : v)                   // use range-for-statement: "for every element of v..."
        ++x;

    print_ints(v, 10);
}

int count_x(const char* p, char x)      // count the number of occurrences of x in p[]     
{
     if (p==nullptr)                    // p is assumed to point to a zero-terminated array of char (or to nothing)
        return 0;
     int count = 0;
     while (*p) {
        if (*p==x)
            ++count;
        ++p;                            // we can advance a pointer to point to the next array element using ++
     }
     return count;
}

void sort(vector<double>& v);           // by using a reference, we ensure that for a call sort(my_vec),
                                        // ...we do not copy my_vec and that it really is my_vec that
                                        // ...is sorted and not a copy of it.

double sum(const vector<double>&);      // we don't want to modify the argument but still don't want the cost of copying


int main() {

    char v[6];              // array of 6 characters (index of 0 to 5)
    char* p;                // pointer to character

    p = &v[3];              // p points to v's fourth element (& = "address of")
    char x = *p;            // *p is the object that p points to (* = "contents of")

    double* pd = nullptr;   // the null pointer ("no object available") - only one nullptr shared by all pointer types

    copy_fct();

    increment();

    cout << count_x("hello", 'l');

    return 0;
}