#include "linsolvers.h"
#include "functions.h"
#include <iostream>

int main()
{
    double epsilon = 1e-15;
    int iterLimit = 10000000;
    double result = 0;
    std::cout << "Solving x+ln(x+0.5)-0.5 = 0 with dichotomy method on [0,3] interval, ";
    result = dichotomyMethod(func1,0,3,epsilon,iterLimit);
    std::cout << "X=" << result << std::endl;

    std::cout << "Solving x^5-x-0.2 = 0 with iteration method on [1,11] interval, ";
    result = iterationMethod(func2,5,epsilon,iterLimit);
    std::cout << "X=" << result << std::endl;

    std::cout << "Solving (2/3)*sin(x)^2 - (3/4)cos(x)^2 = 0 with chord method on [0,pi/2] interval, ";
    result = chordMethod(func3,0,M_PI/2,epsilon,iterLimit);
    std::cout << "X=" << result << std::endl;

    std::cout << "Solving x^5-x-0.2 = 0 with newton method on [1,11] interval, ";
    result = newtonMethod(func2,5,epsilon,iterLimit);
    std::cout << "X=" << result << std::endl;
    //std::cout << "2: " << std::endl;
    //std::cout << "3: (2*sin(x)^2)/3 - (3*cos(x)^2)/4" << std::endl;

    return 0;
}
