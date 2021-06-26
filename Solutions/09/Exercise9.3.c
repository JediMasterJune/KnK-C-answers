//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int computeGcd(int a, int b);

int main(void)
{
    int num1, num2;
    printf("두 숫자를 입력 : ");
    scanf("%d%d", &num1, &num2);
    
    printf("최대공약수는 %d 입니다.\n", computeGcd(num1, num2));
    
    
    return 0;
}

int computeGcd(int a, int b)
{
    int gcd;
    
    /*
    for (int i = 2; i < num1 || i < num2; ++i) { // My algorithm
        if (num1 % i == 0 && num2 % i == 0) {
            gcd = i;
        }
    }
    */
    
    while (b != 0) { //유클리드
        gcd = b;
        b = a % b;
        a = gcd;
    }
    
    return gcd;
    
}
