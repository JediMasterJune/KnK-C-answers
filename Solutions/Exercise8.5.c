//
// Created by JediMasterJune on 21. 3. 28..
//

#include <stdio.h>

#define SIZE (sizeof(fib_numbers)/sizeof(fib_numbers[0]))

int main(void)
{
    int fib_numbers[40] = {0, 1};
    for (int i = 0; i < SIZE - 2; ++i) {
        fib_numbers[i + 2] = fib_numbers[i] + fib_numbers[i + 1];
    }
    
    printf("피보나치 수열 : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", fib_numbers[i]);
    }
    
    
    return 0;
}