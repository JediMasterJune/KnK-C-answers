//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

#define N (sizeof(v1)/sizeof(v1[0]))

double inner_product(double a[], double b[], int n);

int main(void)
{
    double v1[3] = {1, 3, 3};
    double v2[3] = {6, 5, -7};
    
    printf("The inner product of the two vectors: %f\n", inner_product(v1, v2, RANGE));
    
    return 0;
}

double inner_product(double a[], double b[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}
