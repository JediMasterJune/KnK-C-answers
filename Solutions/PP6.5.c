//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num;
    int temp;
    int count = 0;
    printf("뒤집을 숫자 입력 : ");
    scanf("%d", &num);
    
    temp = num;
    do {
        temp /= 10;
        count++;
    } while (temp);
    
    printf("뒤집힌 숫자 : ");
    for (int i = 1, divider = 1; i <= count; ++i) {
        divider = 1;
        for (int j = 1; j < i; ++j) { //현재 자리가 10의 n제곱 자리라고 할 때, 10의 n제곱을 구한다.
            divider *= 10;
        }
        printf("%d", (num % (divider * 10)) / divider); // 10의 n+1제곱으로 나눈 나머지를 10의 n제곱으로 나누면 현재 자리의 숫자를 알 수 있다.
    }
    printf("\n");
    
    return 0;
}