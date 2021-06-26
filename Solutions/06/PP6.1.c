//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    double num, max = 0;
    
    do {
        printf("Enter a number : ");
        scanf("%lf", &num);
        if (num > max) {
            max = num;
        }
    } while (num > 0);
    
    printf("최댓값은 ");
    printf("%.2f 입니다.\n", max);
    
    return 0;
}