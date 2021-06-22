//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int ean[12] = {0};
    int check;
    int total;
    
    printf("Enter your EAN : ");
    for (int i = 0; i < 12; ++i)
    {
        scanf("%1d", ean + i);
    }
    
    for (int i = 0; i < 12 / 2; ++i) // to exclude fourteenth
    {
        total += ean[2 * i + 1];
    }
    total *= 3;
    
    for (int i = 0; i < 12 / 2; ++i) // to exclude thirteenth
    {
        total += ean[2 * i];
    }
    
    printf("total = %d\n", total);
    total--;
    
    check = 9 - (total % 10);
    printf("the check is : %d\n", check);
    
    return 0;
}