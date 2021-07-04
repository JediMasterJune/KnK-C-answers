//
//

#include <stdio.h>

struct date
{
    int month, day, year;
};

int dayofYear(struct date d); // (a)
int compareDates(struct date d1, struct date d2); // (b)

int main(void)
{
    struct date present = {7, 5, 2021};
    struct date future = {3, 28, 2022};
    printf("The day of year: %d\n", dayofYear(present));
    printf("Test of dates result: %d\n", compareDates(present, future));
    
    return 0;
}

int dayofYear(struct date d) // (a)
{
    int day = d.day;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.year % 4 == 0)
        days[1] = 29;
    
    for (int i = 1; i < d.month; ++i) {
        day += days[i - 1];
    }
    return day;
}

int compareDates(struct date d1, struct date d2) // (b)
{
    int day1 = dayofYear(d1), day2 = dayofYear(d2);
    day1 += d1.year * 1000, day2 += d2.year * 1000;
    
    return (day1 > day2) ? -1 : ((day1 < day2) ? 1 : 0);
}
