// Equatation Root of sin(x)

#include <stdio.h>
#include <math.h>
#include <float.h>

double search(double negPoint, double posPoint) {
    
    double midPoint = (negPoint + posPoint) / 2.0;
    
    if (fabs(negPoint - posPoint) < 0.001)
        return midPoint;
    else {
        double testValue = sin(midPoint);
        if (testValue > 0)
            return search(negPoint, midPoint);
        if (testValue < 0)
            return search(midPoint, posPoint);
    }
    return midPoint;
}


double halfIntervalMethod(double x, double y) {
    
    double a = sin(x);
    double b = sin(y);
    
    if (a < 0 && b > 0)
        return search(x,y);
    
    if (a > 0 && b < 0)
        return search(y, x);
    
    return -DBL_MAX;
}



int main(int argc, const char * argv[]) {
    
    double result = halfIntervalMethod(2.0, 4.0);
    
    if (result == -DBL_MAX)
    {
        printf("Wrong coverage\n");
    }
    else
        printf("%f\n", result);
    
    
}
