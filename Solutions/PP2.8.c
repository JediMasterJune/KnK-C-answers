//
// Created by JediMasterJune on 21. 2. 24..
//
// Calculates the remaining balance on a loan after the first, second, and third monthly payments

#include <stdio.h>

int main(void)
{
    double loan, rate, monthly;
    
    printf("Enter amount of loan : ");
    scanf("%lf",&loan);
    printf("Enter interest rate(per year) : ");
    scanf("%lf",&rate);
    printf("Enter monthly payment : ");
    scanf("%lf",&monthly);
    
    loan = (loan-monthly) + (loan * rate / 100 / 12);
    printf("Balance remaining after first payment : %.2f\n",loan);
    
    loan = (loan-monthly) + (loan * rate / 100 / 12);
    printf("Balance remaining after second payment : %.2f\n",loan);
    
    loan = (loan-monthly) + (loan * rate / 100 / 12);
    printf("Balance remaining after third payment : %.2f\n",loan);
    
    return 0;
}