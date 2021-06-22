//
// Created by JediMasterJune on 21. 2. 25..
//

#include <stdio.h>

int main(void)
{
    int son1, mom1, son2, mom2, finalson, finalmom;
    
    printf("분수 1 입력 : ");
    scanf("%d /%d", &son1, &mom1); // /문자가 오기 전에 공백을 허용하기 위해서 format string 내의 %d 다음에 공백 삽입
    
    printf("분수 2 입력 : ");
    scanf("%d /%d", &son2, &mom2);
    
    finalson = son1 * mom2 + son2 * mom1;
    finalmom = mom1 * mom2;
    
    printf("두 분수의 합 : %d/%d\n", finalson, finalmom);
    
    return 0;
}