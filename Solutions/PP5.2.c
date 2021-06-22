//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int hour, minute;
    
    printf("24시간 형식 시각을 입력하십시오 : ");
    scanf("%d : %d", &hour, &minute);
    if (hour > 12)
    {
        printf("%.2d : %.2d ", hour - 12, minute);
        printf("PM\n");
    }
    else
    {
        printf("%.2d : %.2d ", hour, minute);
        if (hour == 12)
        {
            printf("PM\n");
        }
        else
        {
            printf("AM\n");
        }
    }
    
    return 0;
}