//
// Created by JediMasterJune on 21. 6. 10..
//
#include <stdio.h>

#define SIZE (sizeof(a)/sizeof(a[0]))

double innerProduct(const double* a, const double* b, int n);

int main(void)
{
    double a[3] = {1.5, 2.0, 3.0}, b[3] = {4.0, 5.5, 6.0};
    printf("a . b = %f\n", innerProduct(a, b, SIZE));
    
    return 0;
    
}

double innerProduct(const double* a, const double* b, int n)
{
    double sum = 0;
    double* p = a;
    //for (int i = 0; i < 3; i++) {
    while (a < p + n) {
        sum += (*(a++)) * (*(b++));
        printf("%f ", sum);
    }
    printf("\n");
    
    return sum;
}
