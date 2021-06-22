//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int i, n, odd, square;
    
    printf("이 프로그램은 제곱수의 표를 출력합니다.\n");
    printf("표에 출력할 제곱수의 개수를 입력하세요 : ");
    scanf("%d", &n);
    
    i = 1, odd = 3, square = 1;
    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, square);
        square += odd;
        odd += 2;
    }
    
    return 0;
}