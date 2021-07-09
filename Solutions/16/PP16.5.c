//
//

#include <stdio.h>

struct clock {
    int departure, arrival;
};

int main(void)
{
    int hour, min;
    int time;
    struct clock timeTable[8] = {{8 * 60,       10 * 60 + 16},
                                 {9 * 60 + 43,  11 * 60 + 52},
                                 {11 * 60 + 19, 13 * 60 + 31},
                                 {12 * 60 + 47, 15 * 60},
                                 {14 * 60,      16 * 60 + 8},
                                 {15 * 60 + 45, 17 * 60 + 55},
                                 {19 * 60,      21 * 60 + 20},
                                 {21 * 60 + 45, 11 * 60 + 58}};
    int selected;
    
    printf("현재 시각 입력(24시간제) : ");
    scanf("%d : %d", &hour, &min);
    time = hour * 60 + min; // 단위를 분으로 통합
    
    selected = 0;
    for (int i = 0; i < 8; ++i) {
        if (((time - timeTable[selected].departure) > 0 ? time - timeTable[selected].departure : -(time -
                                                                                                   timeTable[selected].departure))
            > ((time - timeTable[i].departure) > 0 ? time - timeTable[i].departure : -(time -
                                                                                       timeTable[i].departure)))
            //입력된 시각과 시간표의 시각과의 '차'(절댓값)를 구하고, 모든 index와 순차적으로 비교
        {
            selected = i;
        }
    }
    
    printf("Closest departure time is ");
    if (timeTable[selected].departure / 60 > 12) {
        printf("%.2d : %.2d PM, ", timeTable[selected].departure / 60 - 12, timeTable[selected].departure % 60);
    }
    else {
        if (timeTable[selected].departure / 60 == 12) {
            printf("%.2d : %.2d PM, ", timeTable[selected].departure / 60, timeTable[selected].departure % 60);
        }
        else {
            printf("%.2d : %.2d AM, ", timeTable[selected].departure / 60, timeTable[selected].departure % 60);
        }
    }
    
    printf("arriving at ");
    if (timeTable[selected].arrival / 60 > 12) {
        printf("%.2d : %.2d PM.\n", timeTable[selected].arrival / 60 - 12,
               timeTable[selected].arrival % 60); //13~23시는 모두 오후
    }
    else {
        if (timeTable[selected].arrival / 60 == 12) {
            printf("%.2d : %.2d PM.\n", timeTable[selected].arrival / 60, timeTable[selected].arrival % 60); //12시는 오후
        }
        else {
            printf("%.2d : %.2d AM.\n", timeTable[selected].arrival / 60, timeTable[selected].arrival % 60);
        }
    }
    
    return 0;
}