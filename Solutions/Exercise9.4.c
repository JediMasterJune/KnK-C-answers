//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

int day_of_year(int month, int day, int year);

int main(void)
{
    int month, day, year;
    printf("Enter month, day, and year(MM/DD/YYYY):");
    scanf("%d /%d /%d", &month, &day, &year);
    
    printf("The day of the year : %d\n", day_of_year(month, day, year));
    
    return 0;
}

int day_of_year(int month, int day, int year)
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        days[1] = 29;
    }
    
    for (int i = 0; i < month - 1; ++i) {
        day += days[i];
    }
    
    return day;
}
