//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int selectedDepart[8] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
int arrival[8] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20,
                  11 * 60 + 58};

void findClosestFlight(int desiredTime, int* p_departureTime, int* p_arrivalTime);
int findAbsolute(int num);

int main(void)
{
    int hour, min;
    int time;
    int selectedDepart, selectedArrival;
    
    printf("현재 시각 입력(24시간제) : ");
    scanf("%d : %d", &hour, &min);
    time = hour * 60 + min; // 단위를 분으로 통합
    
    findClosestFlight(time, &selectedDepart, &selectedArrival);
    
    
    printf("Closest Departure time is ");
    if (selectedDepart / 60 > 12) { //오후일 경우
        printf("%.2d : %.2d PM, ", selectedDepart / 60 - 12, selectedDepart % 60); // 시는 12시간 빼서 표현
    }
    else {
        if (selectedDepart / 60 == 12) {
            printf("%.2d : %.2d PM, ", selectedDepart / 60, selectedDepart % 60); // 오후 12시일때
        }
        else {
            printf("%.2d : %.2d AM, ", selectedDepart / 60, selectedDepart % 60); //12보다 작으면
        }
    }
    
    printf("arriving at ");
    if (selectedArrival / 60 > 12) {
        printf("%.2d : %.2d PM.\n", selectedArrival / 60 - 12, selectedArrival % 60); //13~23시는 모두 오후
    }
    else {
        if (selectedArrival / 60 == 12) {
            printf("%.2d : %.2d PM.\n", selectedArrival / 60, selectedArrival % 60); //12시는 오후
        }
        else {
            printf("%.2d : %.2d AM.\n", selectedArrival / 60, selectedArrival % 60);
        }
    }
    
    return 0;
}

int findAbsolute(int num)
{
    return (num > 0) ? num : -num;
}

void findClosestFlight(int desiredTime, int* p_departureTime, int* p_arrivalTime)
{
    int selected = 0;
    
    for (int i = 1; i < 8; ++i) {
        if (findAbsolute(desiredTime - selectedDepart[selected]) > findAbsolute(desiredTime - selectedDepart[i])) {
            selected = i;
        }
    }
    
    *(p_departureTime) = selectedDepart[selected];
    *(p_arrivalTime) = arrival[selected];
    
}
