#include "linsolvers.h"

double dichotomyMethod(double (*solvedFunction)(double), double from, double to, double epsilon, int iterationLimit) {
    double midPoint = 0;
    double i = 0;
    while(fabs(to-from) > epsilon)
    {
        midPoint = (from+to)/2;

        if(solvedFunction(to) * solvedFunction(midPoint) < 0)
        {
            from = midPoint;
        }
        else
        {
            to = midPoint;
        }

        i++;
        if(i == iterationLimit)
        {
            break;
        }
    }

    return (from+to)/2;
}

double derivativeAtPoint(double (*targetFunc)(double), double x, double eps)
{
    return (targetFunc(x+eps)-targetFunc(x))/eps;
}

double calculatePhi(double (*targetFunc)(double), double x)
{
    return x - ((1/derivativeAtPoint(targetFunc,x,EPSILON_INTERNAL)) * targetFunc(x));
}

double iterationMethod(double (*solvedFunction)(double), double startingPoint, double epsilon, int iterationLimit) {
    int i = 0;

    while(fabs(solvedFunction(startingPoint)) > epsilon)
    {
        startingPoint = calculatePhi(solvedFunction, startingPoint);

        i++;
        if (i == iterationLimit) {
            break;
        }
    }

    return startingPoint;
}

double chordMethod(double (*solvedFunction)(double), double from, double to, double epsilon, int iterationLimit) {
    int i = 0;

    while(fabs(to - from) > epsilon) {
        from = to - (to - from) * solvedFunction(to) / (solvedFunction(to) - solvedFunction(from));
        to = from - (from - to) * solvedFunction(from) / (solvedFunction(from) - solvedFunction(to));

        // f != f is true only for NaNs, check if we gone too far and divided by zero due to losing precision
        if(to != to) return from;
        if(from != from) return to;

        i++;
        if(i == iterationLimit)
        {
            break;
        }
    }

    return to;
}

double newtonMethod(double (*solvedFunction)(double), double startingPoint, double epsilon, int iterationLimit) {
    int i = 0;

    while(fabs(solvedFunction(startingPoint)) > epsilon) {
        startingPoint = startingPoint - (solvedFunction(startingPoint) / derivativeAtPoint(solvedFunction, startingPoint, EPSILON_INTERNAL));

        i++;
        if (i == iterationLimit)
        {
            break;
        }
    }

    return startingPoint;
}
