#ifndef CPP1_TASK_LINSOLVERS_H
#define CPP1_TASK_LINSOLVERS_H

#include <cmath>

const double EPSILON_INTERNAL = 1e-15;

double dichotomyMethod(double (*solvedFunction)(double),double from, double to, double epsilon, int iterationLimit);

double iterationMethod(double (*solvedFunction)(double), double startingPoint, double epsilon, int iterationLimit);

double chordMethod(double (*solvedFunction)(double),double from, double to, double epsilon, int iterationLimit);

double newtonMethod(double (*solvedFunction)(double), double startingPoint, double epsilon, int iterationLimit);

#endif //CPP1_TASK_LINSOLVERS_H
