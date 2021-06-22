//
// Created by JediMasterJune on 21. 3. 28..
//

#include <stdio.h>

#define MONTH 30
#define HOUR 24

int main(void)
{
    int temperatureReadings[MONTH][HOUR] = {0};
    int hourSum[30] = {0};
    double daily[30];
    double avgSum = 0.0;
    double monthly;
    for (int i = 0; i < MONTH; ++i) {
        for (int j = 0; j < HOUR; ++j) {
            hourSum[i] += temperatureReadings[i][j];
        }
    }
    
    for (int i = 0; i < MONTH; ++i) {
        daily[i] = (double) hourSum[i] / HOUR;
        avgSum += daily[i];
    }
    monthly = avgSum / MONTH;
    
    printf("daily average\n");
    for (int i = 0; i < MONTH; ++i) {
        printf("%-5d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < MONTH; ++i) {
        printf("%-5.1f ", daily[i]);
    }
    
    printf("\nmonthly average : %g\n", monthly);
    
    return 0;
}