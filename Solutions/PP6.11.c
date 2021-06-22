//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int n;
    int iFact;
    double e = 1;
    
    printf("enter your maximum integer : ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        iFact = 1;
        for (int j = 1; j <= i; ++j) { // compute i factorial
            iFact *= j;
        }
        e += (double) 1 / iFact;
    }
    
    printf("e is %f\n", e);
    
    return 0;
}