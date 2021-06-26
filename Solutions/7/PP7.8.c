//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, min;
    int time;
    int departure[8] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    int arrival[8] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20,
                      11 * 60 + 58};
    int selected;
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
    printf("현재 시각 = %d : %d\n", hour, min);
    time = hour * 60 + min; // 단위를 분으로 통합
    
    selected = 0;
    for (int i = 0; i < 8; ++i) {
        if (((time - departure[selected]) > 0 ? time - departure[selected] : -(time - departure[selected]))
            > ((time - departure[i]) > 0 ? time - departure[i] : -(time -
                                                                   departure[i])))
            //입력된 시각과 시간표의 시각과의 '차'(절댓값)를 구하고, 모든 index와 순차적으로 비교
        {
            selected = i;
        }
    }
    
    printf("Closest selectedDepart time is ");
    if (departure[selected] / 60 > 12) {
        printf("%.2d : %.2d PM, ", departure[selected] / 60 - 12, departure[selected] % 60);
    }
    else {
        if (departure[selected] / 60 == 12) {
            printf("%.2d : %.2d PM, ", departure[selected] / 60, departure[selected] % 60);
        }
        else {
            printf("%.2d : %.2d AM, ", departure[selected] / 60, departure[selected] % 60);
        }
    }
    
    printf("arriving at ");
    if (arrival[selected] / 60 > 12) {
        printf("%.2d : %.2d PM.\n", arrival[selected] / 60 - 12, arrival[selected] % 60); //13~23시는 모두 오후
    }
    else {
        if (arrival[selected] / 60 == 12) {
            printf("%.2d : %.2d PM.\n", arrival[selected] / 60, arrival[selected] % 60); //12시는 오후
        }
        else {
            printf("%.2d : %.2d AM.\n", arrival[selected] / 60, arrival[selected] % 60);
        }
    }
    
    return 0;
}