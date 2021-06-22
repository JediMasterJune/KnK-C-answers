//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

int digit(int n, int k);

int main(void)
{
    int num, k;
    printf("Enter a number and the position of the digit from right: ");
    scanf("%d%d", &num, &k);
    
    printf("The digit in position %d is %d\n", k, digit(num, k));
    
    return 0;
}

int digit(int n, int k)
{
    for (int i = 0; i < k - 1; ++i) {
        n /= 10;
    }
    return (n % 10);
}
