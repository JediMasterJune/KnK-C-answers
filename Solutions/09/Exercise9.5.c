//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

int num_digits(int n);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("The digits of the number: %d\n", num_digits(num));
    
    return 0;
}

int num_digits(int n)
{
    int digits = 0;
    while (n > 0) {
        n /= 10;
        digits++;
    }
    return digits;
}
