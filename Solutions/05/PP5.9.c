//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int month1, day1, year1;
    int month2, day2, year2;
    int time1, time2;
    
    printf("Enter your First date(mm/dd/yy) : ");
    scanf("%d /%d /%d", &month1, &day1, &year1);
    
    printf("Enter your Second date(mm/dd/yy) : ");
    scanf("%d /%d /%d", &month2, &day2, &year2);
    
    time1 = year1 * 10000 + month1 * 100 + day1;
    time2 = year2 * 10000 + month2 * 100 + day2;
    
    if (time1 < time2)
    {
        printf("Earlier date is %d/%d/%d\n", month1, day1, year1);
    }
    else
    {
        printf("Earlier date is %d/%d/%d\n", month2, day2, year2);
    }
    
    return 0;
}