//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int n;
    
    printf("n이하의 제곱수 중 짝수의 제곱수를 모두 출력합니다.\n n을 입력하세요 : ");
    scanf("%d", &n);
    
    for (int i = 1; i * i <= n; ++i) {
        if (i % 2 == 0)
            printf("%d ", i * i);
    }
    printf("\n");
    
    return 0;
}