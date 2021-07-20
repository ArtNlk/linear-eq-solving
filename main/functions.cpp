#include "functions.h"

double func1(double x) {
    return x + log(x + 0.5) - 0.5;
}

double func2(double x) {
    return pow(x,5) - x - 0.2;
}

double func3(double x) {
    return (2.0/3.0) * sin(x) * sin(x) - (3.0/4.0) * cos(x) * cos(x);
}
