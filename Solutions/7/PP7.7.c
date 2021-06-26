//
// Created by JediMasterJune on 21. 2. 25..
//

#include <stdio.h>

int main(void)
{
    int son1, mom1, son2, mom2, finalSon, finalMom;
    char operator;
    
    printf("두 분수 사칙연산 입력 : ");
    //scanf("%d /%d + %d /%d", &son1, &mom1, &son2, &mom2); // /문자가 오기 전에 공백을 허용하기 위해서 format string 내의 %d 다음에 공백 삽입
    
    scanf("%d /%d ", &son1, &mom1);
    operator = getchar();
    scanf("%d /%d", &son2, &mom2);
    
    switch (operator) {
        case '+':
            finalSon = son1 * mom2 + son2 * mom1;
            finalMom = mom1 * mom2;
            printf("두 분수의 합 : %d/%d\n", finalSon, finalMom);
            break;
        case '-':
            finalSon = son1 * mom2 - son2 * mom1;
            finalMom = mom1 * mom2;
            printf("두 분수의 차 : %d/%d\n", finalSon, finalMom);
            break;
        case '*':
            finalSon = son1 * son2;
            finalMom = mom1 * mom2;
            printf("두 분수의 곱 : %d/%d\n", finalSon, finalMom);
            break;
        case '/':
            finalSon = son1 * mom2;
            finalMom = mom1 * son2;
            printf("두 분수의 몫 : %d/%d\n", finalSon, finalMom);
            break;
        default:
            return -1;
    }
    
    return 0;
}