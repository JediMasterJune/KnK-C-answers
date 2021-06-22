//
// Created by JediMasterJune on 21. 2. 25..
//

#include <stdio.h>

int main(void)
{
    int son1, mom1, son2, mom2, finalSon, finalMom;
    
    printf("두 분수 덧셈 입력 : ");
    scanf("%d /%d + %d /%d", &son1, &mom1, &son2, &mom2); // /문자가 오기 전에 공백을 허용하기 위해서 format string 내의 %d 다음에 공백 삽입
    
    finalSon = son1 * mom2 + son2 * mom1;
    finalMom = mom1 * mom2;
    
    printf("두 분수의 합 : %d/%d\n", finalSon, finalMom);
    
    return 0;
}