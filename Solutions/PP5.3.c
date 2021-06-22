//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    double commission, value, pricePerShare, rivalCommission;
    int share;
    
    //printf("Enter value of trade :");
    //scanf("%lf", &value);
    
    printf("주식 수량을 입력 : ");
    scanf("%d", &share);
    
    printf("주식의 주당 가격을 입력 : ");
    scanf("%lf", &pricePerShare);
    
    value = share * pricePerShare;
    printf("총 value = %.2f\n", value);
    
    if (value < 2500)
    {
        commission = 30 + 0.017 * value;
    }
    else if (value < 6250)
    {
        commission = 56 + 0.0066 * value;
    }
    else if (value < 20000)
    {
        commission = 76 + 0.0034 * value;
    }
    else if (value < 50000)
    {
        commission = 100 + 0.0022 * value;
    }
    else if (value < 500000)
    {
        commission = 155 + 0.0011 * value;
    }
    else
    {
        commission = 255 + 0.0009 * value;
    }
    if (commission < 39)
    {
        commission = 39;
    }
    
    printf("Original Commission : %.2f\n", commission);
    
    if (share < 2000)
    {
        rivalCommission = 33 + 0.03 * share;
    }
    else
    {
        rivalCommission = 33 + 0.02 * share;
    }
    
    printf("Rival's Commission : %.2f\n", rivalCommission);
    
    return 0;
}