//
// Created by JediMasterJune on 21. 2. 24..
//
// Computes the dimensional weight of a 12" x 10" x 8" box

#include <stdio.h>

int Exponentate(int, int);

int main(void)
{
    int x;
    
    printf("x 값 입력 : ");
    scanf("%d", &x);
    
    printf("결과 : %d\n",
           3 * Exponentate(x, 5) + 2 * Exponentate(x, 4) - 5 * Exponentate(x, 3) - x * x + 7 * x - 6);
    printf("결과 : %d\n",
           3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);
    printf("x의 5제곱 : %d\n", Exponentate(x, 5));
    return 0;
}

int Exponentate(int x, int times)
{
    /* for (int i = 1; i < times; i++)
    {
        x*=x; // 매우 주의 : 제곱된 x가 다시 제곱됨.
    }*/
    if (times == 0)
        return 1;
    else
        return x * Exponentate(x, times - 1); //재귀함수
}
