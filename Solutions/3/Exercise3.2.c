//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    double var = 10.12;
    printf("%-8.1e\n", var);
    printf("%10.6e\n", var);
    printf("%-8.3f\n", var);
    printf("%6.0f\n", var);
    return 0;
}