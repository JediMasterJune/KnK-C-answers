//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int i, odd, square;
    
    printf("이 프로그램은 제곱수의 표를 출력합니다.\n");
    
    i = 1, odd = 3, square = 1;
    for (i = 1; square > 0; i++) {
        printf("%20d%20d\n", i, square);
        square += odd;
        odd += 2;
    }
    printf("n = %d\n", i);
    
    return 0;
}