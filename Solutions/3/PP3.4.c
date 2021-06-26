//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int region, first, second;
    printf("Enter phone number : ");
    scanf("%d ) %d - %d", &region, &first, &second);
    
    printf("You entered %.3d.%d.%d\n", region, first, second);
    
    return 0;
}