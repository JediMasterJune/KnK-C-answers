//
// Created by JediMasterJune on 21. 2. 24..
//
// Calculates the remaining balance on a loan after the first, second, and third monthly payments

#include <stdio.h>

int main(void)
{
    double loan, rate, monthly;
    int payTimes;
    
    printf("Enter amount of loan : ");
    scanf("%lf", &loan);
    printf("Enter interest rate(per year) : ");
    scanf("%lf", &rate);
    printf("Enter monthly payment : ");
    scanf("%lf", &monthly);
    printf("Enter your number of payment(s) : ");
    scanf("%d", &payTimes);
    
    for (int i = 0; i < payTimes; ++i)
    {
        loan = (loan - monthly) + (loan * rate / 100 / 12);
        printf("Balance remaining after payment %d : %.2f\n", i + 1, loan);
    }
    
    return 0;
}