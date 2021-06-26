//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int num;
    int digit[5] = {0};
    
    printf("8진수로 변환할 숫자를 입력 (32767까지) : ");
    scanf("%d", &num);
    for (int i = 0; i < 5; ++i)
    {
        int temp = num;
        int divider = 1;
        for (int j = 0; j <= i; ++j)
        {
            divider *= 8;
        }
        temp %= divider;
        for (int k = 0; k < i; ++k)
        {
            temp /= 8;
        }
        digit[i] = temp;
    }
    
    /*
    digit[0] = num % 8;
    digit[1] = num % (8 * 8) / 8;
    digit[2] = num / (8 * 8);
    digit[3] = num / (8 * 8 * 8);
    digit[4] = num / (8 * 8 * 8 * 8);
    */
    
    printf("변환된 숫자 : ");
    for (int i = 4; i >= 0; --i)
    {
        printf("%d", digit[i]);
    }
    printf("\n");
    
    return 0;
}