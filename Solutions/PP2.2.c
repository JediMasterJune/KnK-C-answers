//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>
#define PI 3.1415926535

int main(void)
{
    int radius;
    printf("반지름 입력 : ");
    scanf("%d",&radius);
    printf("구의 부피 : %.3f\n",(radius*radius*radius)*(4.0/3.0)*PI);
    return 0;
}