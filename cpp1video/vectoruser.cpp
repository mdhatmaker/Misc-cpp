// vectoruser.cpp

#include "Vector.h"         // get Vector's interface
#include <cmath>            // get the standard-library math function interface including sqrt()
#include <iostream>

/*
create a .o file:
 g++ -std=c++11 -c Vector.cpp

add this file to a library, creating library if necessary:
 ar rvs Vector.a Vector.o

use library:
 g++ -std=c++11 vectoruser.cpp Vector.a
*/

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum+=std::sqrt(v[i]);           // sum of square roots
    return sum;
}


int main() {
    std::cout << "running vectoruser.cpp" << std::endl;

    return 0;
}