//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int year, month, day;
    printf("날짜를 월/일/연도 형식으로 입력하세요 : ");
    scanf("%d /%d /%d", &month, &day, &year);
    printf("입력하신 날짜는 %d%.2d%.2d\n", year, month, day);
    return 0;
}