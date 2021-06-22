//
// Created by JediMasterJune on 21. 5. 21..
//

#include <stdio.h>
#include <math.h>

double computePolynomial(double x);

int main(void)
{
    double x;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("The result is %f\n", computePolynomial(x));
    
    return 0;
}

double computePolynomial(double x)
{
    return (3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6);
}
