//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num1, num2;
    int gcd;
    
    printf("두 숫자를 입력 : ");
    scanf("%d%d", &num1, &num2);
    
    /*
    for (int i = 2; i < num1 || i < num2; ++i) { // My algorithm
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    */
    
    while (num2 != 0) { //유클리드
        gcd = num2;
        num2 = num1 % num2;
        num1 = gcd;
    }
    
    printf("최대공약수는 %d 입니다.\n", gcd);
    
    
    return 0;
}