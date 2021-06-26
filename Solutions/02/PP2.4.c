//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>

int main(void)
{
    double dollar;
    printf("enter your dollars-and-cents amount : ");
    scanf("%lf", &dollar);
    printf("With 5%% tax added : %.2f\n", dollar * 1.05);
    return 0;
}