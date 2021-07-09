//
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR(...) fprintf(stderr, __VA_ARGS__)

typedef struct fraction
{
    int numerator, denominator;
} Fraction;

Fraction FracReduce(Fraction origin); //(a)
Fraction FracAdd(Fraction f1, Fraction f2); //(b)
Fraction FracSub(Fraction f1, Fraction f2); //(c)
Fraction FracMul(Fraction f1, Fraction f2); //(d)
Fraction FracDiv(Fraction f1, Fraction f2); //(e)

int getGCD(int a, int b);

int main(void)
{
    Fraction frac1 = {2, 4}, frac2 = {5, 7};
    Fraction added, subtracted, multiplied, divided;
    
    added = FracAdd(frac1, frac2);
    subtracted = FracSub(frac1, frac2);
    multiplied = FracMul(frac1, frac2);
    divided = FracDiv(frac1, frac2);
    
    printf("%d/%d = %d/%d\n", frac1.numerator, frac1.denominator, FracReduce(frac1).numerator,
           FracReduce(frac1).denominator);
    printf("%d/%d + %d/%d = %d/%d\n", frac1.numerator, frac1.denominator, frac2.numerator, frac2.denominator,
           added.numerator, added.denominator);
    printf("%d/%d - %d/%d = %d/%d\n", frac1.numerator, frac1.denominator, frac2.numerator, frac2.denominator,
           subtracted.numerator, subtracted.denominator);
    printf("%d/%d * %d/%d = %d/%d\n", frac1.numerator, frac1.denominator, frac2.numerator, frac2.denominator,
           multiplied.numerator, multiplied.denominator);
    printf("%d/%d * %d/%d = %d/%d\n", frac1.numerator, frac1.denominator, frac2.numerator, frac2.denominator,
           divided.numerator, divided.denominator);
    
    return 0;
    
}

Fraction FracReduce(Fraction origin)
{
    int gcd = getGCD(origin.numerator, origin.denominator);
    origin.numerator /= gcd;
    origin.denominator /= gcd;
    
    return origin;
}

Fraction FracAdd(Fraction f1, Fraction f2)
{
    Fraction result;
    
    int gcd;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    
    gcd = getGCD(result.denominator, result.numerator);
    result.denominator /= gcd;
    result.numerator /= gcd;
    
    return result;
    
}

Fraction FracSub(Fraction f1, Fraction f2)
{
    Fraction result;
    
    int gcd;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    
    gcd = getGCD(result.denominator, result.numerator);
    result.denominator /= gcd;
    result.numerator /= gcd;
    
    return result;
    
}

Fraction FracMul(Fraction f1, Fraction f2)
{
    Fraction result;
    
    int gcd;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.numerator;
    
    gcd = getGCD(result.denominator, result.numerator);
    result.denominator /= gcd;
    result.numerator /= gcd;
    
    return result;
    
}

Fraction FracDiv(Fraction f1, Fraction f2) //(e)
{
    if (f2.numerator == 0) {
        ERROR("Diveded by zero!!!!!!!!\n");
        exit(EXIT_FAILURE);
    }
    Fraction result;
    
    int gcd;
    result.denominator = f1.denominator * f2.numerator;
    result.numerator = f1.numerator * f2.denominator;
    
    gcd = getGCD(result.denominator, result.numerator);
    result.denominator /= gcd;
    result.numerator /= gcd;
    
    return result;
}

int getGCD(int a, int b)
{
    if (b == 0) return a;
    else
        return getGCD(b, a % b);
}