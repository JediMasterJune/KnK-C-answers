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
        square += odd; //이전까지의 제곱수가 누적되고 새로운 i번째 홀수를 더함으로써 새 제곱수 생성
        odd += 2; //새로운 홀수 생성
        if (i % 24 == 0) {
            printf("Press Enter to Continue...\n");
            while (getchar() != '\n');
        }
    }
    printf("n = %d\n", i);
    
    return 0;
}