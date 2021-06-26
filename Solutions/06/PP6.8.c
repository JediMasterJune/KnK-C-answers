//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int days, weekday;
    
    printf("말일을 입력하여 주십시오 : ");
    scanf("%d", &days);
    printf("시작 요일을 입력하여 주십시오 (1=Sun, 7=Sat) : ");
    scanf("%d", &weekday);
    
    for (int i = 1; i < weekday; ++i)
    {
        printf("   "); // 2+1칸 띔
    }
    
    for (int i = 1; i <= days;)
    {
        while (weekday <= 7 && i <= days)
        {
            printf("%2d ", i++);
            weekday++;
        }
        printf("\n");
        weekday = 1;
    }
    
    return 0;
}