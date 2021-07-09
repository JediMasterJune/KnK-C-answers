//
//

#include <stdio.h>

struct clock {
    int hours, minutes, seconds;
};

struct clock splitTime(long totalSeconds);

int main(void)
{
    int sec = 13984;
    
    struct clock converted;
    converted = splitTime(sec);
    
    printf("%.2d:%.2d:%.2d\n", converted.hours, converted.minutes, converted.seconds);
    return 0;
}

struct clock splitTime(long totalSeconds)
{
    struct clock result;
    
    result.seconds = totalSeconds % 60;
    result.minutes = (totalSeconds / 60) % 60;
    result.hours = (totalSeconds / 60) / 60;
    
    return result;
}

