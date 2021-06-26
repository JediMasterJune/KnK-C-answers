//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int n;
    long double factorial = 1.0;
    
    //printf("n을 입력하세요 : ");
    //scanf("%d", &n);
    for (n = 0; factorial > 0; ++n) {
        factorial = 1.0;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("%d! = %Lg\n", n, factorial);
        if (n % 50 == 0) {
            printf("계속하려면 엔터 키를 누르십시오...");
            while (getchar() != '\n');
        }
    }
    return 0;
}