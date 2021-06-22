//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>

void payAmount(int dollars, int* twenties, int* tens, int* fives, int* ones);

int main(void)
{
    int dollar;
    int twenties, tens, fives, ones;
    payAmount(dollar, &twenties, &tens, &fives, &ones);
    
    printf("$20 bills : %d\n", twenties);
    printf("$10 bills : %d\n", tens);
    printf("$5 bills : %d\n", fives);
    printf("$1 bills : %d\n", ones);
    
    return 0;
}

void payAmount(int dollars, int* twenties, int* tens, int* fives, int* ones)
{
    printf("Enter a dollar amount : ");
    scanf("%d", &dollars);
    
    *twenties = dollars / 20;
    dollars -= *twenties * 20;
    
    *tens = dollars / 10;
    dollars -= *tens * 10;
    
    *fives = dollars / 5;
    dollars -= *fives * 5;
    
    *ones = dollars;
    
    
}
