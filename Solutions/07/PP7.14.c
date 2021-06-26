//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <math.h>

#define SIGMA 0.00001

int main(void)
{
    double num;
    double rootNum = 1.0;
    double preRoot;
    double sub;
    
    scanf("%lf", &num);
    while (1) {
        preRoot = rootNum;
        sub = fabs((preRoot) - (rootNum = (num / rootNum + rootNum) / 2.0));//double 변수의 절댓값 계산 함수
        //sub = (sub < 0) ? -sub : sub;
        if (sub <= SIGMA)
            break;
    }
    printf("루트 %.5f = %.5f\n", num, rootNum);
    
    return 0;
}