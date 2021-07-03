//
//
// Exercise 16.3 (d)

#include <stdio.h>


struct complex
{
    double real, imaginary;
};

struct complex add_complex(struct complex str1, struct complex str2);

int main(void)
{
    struct complex str1 = {1.0, 2.0}, str2 = {3.0, 4.0};
    struct complex result = add_complex(str1, str2);
    double result1 = result.real, result2 = result.imaginary;
    
    printf("%f %f \n", result1, result2);
    
    return 0;
}

struct complex add_complex(struct complex str1, struct complex str2)
{
    struct complex added;
    added.real = str1.real + str2.real;
    added.imaginary = str1.imaginary + str2.imaginary;
    
    return added;
}