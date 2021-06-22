//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, min;
    char noonCheck;
    
    printf("현재 시각 입력(AM/PM) : ");
    scanf("%d : %d ", &hour, &min);
    while ((noonCheck = getchar()) != '\n') { //그냥 엔터만 칠 경우 while문 탈출 안됨. 앞의 scanf문이 모든 공백을 집어삼킨다!
        noonCheck = toupper(noonCheck);
        if (noonCheck == 'P') {
            if (hour != 12) {
                hour += 12;
            }
        }
        else if (noonCheck == 'A') {
            if (hour == 12)
                hour += 12;
        }
    }
    printf("현재 시각(24시간제) = %d : %d\n", hour, min);
    
    return 0;
}