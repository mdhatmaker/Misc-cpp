#include <iostream> 

using namespace std;

// TIP: The number of errors in code correlates strongly with the amount of code and the
// complexity of the code. Both problems can be addressed by using more and shorter functions.


// A function cannot be called unless it has been previously declared:
//Elem* next_elem();      // no argument; return a pointer to Elem (an Elem*)
void do_exit(int);      // int argument; return nothing
double get9();          // no argument; return a double

// Function declaractions (above) can appear separate from the function body (below).

void do_exit(int i)
{
    double nine = get9();   // we can use get9() function because it was declared
    cout << " nine=" << nine << "\t exit value: " << i << endl;     // '\t' is tab
}

double get9()
{
    return (double)9;   // cast an int to a double
}

// Or the function declaration AND body can be together (below).

double square(double x)     // function returns square of (double) number
{
    return x*x;
}

void print_square(double x)     // function to display number and its square
{
    cout << "the square of " << x << " is " << square(x) << "\n";  // can use special chars like '\n' for newline
}

int main()
{
    print_square(1.234);    // call function
    do_exit(-1);
}