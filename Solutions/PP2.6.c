//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>

int main(void)
{
    int x;
    
    printf("x 값 입력 : ");
    scanf("%d",&x);
    
    printf("결과 : %d\n",
           ((((3*x+2)*x-5)*x-1)*x+7)*x-6);
    
    return 0;
}