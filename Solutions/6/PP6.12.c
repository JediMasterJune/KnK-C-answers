//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int sigma;
    int iFact = 1;
    double realSigma = 1;
    double e = 1;
    
    printf("enter sigma : "); // 소수점 이하 몇자리까지? (1.0e-sigma)
    scanf("%d", &sigma);
    for (int i = 0; i < sigma; ++i) {
        realSigma /= 10;
    } //실제 1.0e-sigma 값을 구했다.
    
    for (int i = 1; ((double) 1 / iFact) > realSigma; ++i) { //iFact가 정수이므로 명시적 형변환
        iFact = 1; //팩토리얼 계산값 초기화
        for (int j = 1; j <= i; ++j) { // compute i factorial
            iFact *= j;
        }
        e += (double) 1 / iFact; //iFact가 정수이므로 명시적 형변환
    }
    
    printf("e is %f\n", e);
    
    return 0;
}