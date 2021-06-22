//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int upc[11] = {0};
    int check;
    int total;
    
    printf("Enter your UPC : ");
    for (int i = 0; i < 11; ++i)
    {
        scanf("%1d", upc + i);
    }
    
    for (int i = 0; i <= 11 / 2; ++i) // to include eleventh
    {
        total += upc[2 * i];
    }
    total *= 3;
    
    for (int i = 0; i < 11 / 2; ++i) // to exclude twelfth
    {
        total += upc[2 * i + 1];
    }
    
    printf("total = %d\n", total);
    total--;
    
    check = 9 - (total % 10);
    printf("the check is : %d\n", check);
    
    return 0;
}