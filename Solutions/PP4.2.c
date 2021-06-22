//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num;
    printf("세 자리 숫자 입력 : ");
    scanf("%3d", &num);
    
    printf("Reversed 숫자 : %d%d%d\n", num % 10, (num % 100) / 10, num / 100);
    
    return 0;
}