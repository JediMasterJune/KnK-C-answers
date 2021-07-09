//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include "dates.h"

int main(void)
{
    struct date date1, date2;
    int time1, time2;
    
    printf("Enter your First date(mm/dd/yy) : ");
    scanf("%d /%d /%d", &date1.month, &date1.day, &date1.year);
    
    printf("Enter your Second date(mm/dd/yy) : ");
    scanf("%d /%d /%d", &date2.month, &date2.day, &date2.year);
    
    time1 = dayofYear(date1), time2 = dayofYear(date2);
    
    //time1 = year1 * 10000 + month1 * 100 + day1;
    //time2 = year2 * 10000 + month2 * 100 + day2;
    
    if (time1 < time2) {
        printf("Earlier date is %d/%d/%d\n", date1.month, date1.day, date1.year);
    }
    else {
        printf("Earlier date is %d/%d/%d\n", date2.month, date2.day, date2.year);
    }
    
    return 0;
}