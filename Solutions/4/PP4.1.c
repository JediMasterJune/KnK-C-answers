//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num;
    printf("두 자리 숫자 입력 : ");
    scanf("%d", &num);
    
    printf("Reversed 숫자 : %d%d\n", num % 10, num / 10);
    
    return 0;
}