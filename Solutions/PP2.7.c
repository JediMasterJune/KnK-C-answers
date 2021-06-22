//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>

int main(void)
{
    int dollar;
    int twenties, tens, fives, ones;
    
    printf("Enter a dollar amount : ");
    scanf("%d", &dollar);
    
    twenties = dollar / 20;
    dollar -= twenties * 20;
    
    tens = dollar / 10;
    dollar -= tens * 10;
    
    fives = dollar / 5;
    dollar -= fives * 5;
    
    ones = dollar;
    
    printf("$20 bills : %d\n", twenties);
    printf("$10 bills : %d\n", tens);
    printf("$5 bills : %d\n", fives);
    printf("$1 bills : %d\n", ones);
    return 0;
}