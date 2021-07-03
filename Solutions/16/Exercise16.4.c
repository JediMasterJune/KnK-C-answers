//
//
// Exercise 16.4

#include <stdio.h>

typedef struct
{
    double real, imaginary;
} Complex; // (a)

Complex add_complex(Complex str1, Complex str2); // (d)
Complex make_complex(double real, double imaginary); // (c)

int main(void)
{
    Complex c1, c2 = {1.0, 2.0}, c3 = {3.0, 4.0}; // (b)
    Complex c4 = make_complex(5.0, 6.0);
    Complex result = add_complex(c2, c3);
    double result1 = result.real, result2 = result.imaginary;
    
    printf("%f %f \n", result1, result2);
    printf("c4 : %f %f \n", c4.real, c4.imaginary);
    
    return 0;
}

Complex make_complex(double real, double imaginary)
{
    Complex new;
    new.real = real;
    new.imaginary = imaginary;
    
    return new;
}

Complex add_complex(Complex str1, Complex str2)
{
    Complex added;
    added.real = str1.real + str2.real;
    added.imaginary = str1.imaginary + str2.imaginary;
    
    return added;
}