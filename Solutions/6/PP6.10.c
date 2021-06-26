//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int month, day, year;
    int time;
    printf("Enter a date(mm/dd/yy) : ");
    scanf("%d /%d /%d", &month, &day, &year);
    time = year * 10000 + month * 100 + day;
    
    while (month || day || year) {
        if (year * 10000 + month * 100 + day < time) {
            time = year * 10000 + month * 100 + day; // ex : 03/16/21 -> 210000+300+16 = 210316
        }
        printf("Enter a date(mm/dd/yy) : ");
        scanf("%d /%d /%d", &month, &day, &year);
    }
    
    printf("Earliest date is %d/%d/%d\n", (time % 10000) / 100, time % 100, time / 10000);
    
    return 0;
}