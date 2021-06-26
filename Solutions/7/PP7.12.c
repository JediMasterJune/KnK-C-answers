//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    double num = 0.0;
    double result = 0.0;
    char operator = '+';
    while (true) {
        if (operator == '\n')
            break;
        scanf("%lf", &num);
        switch (operator) {
            case '+':
                result += num;
                break;
            case '-':
                result -= num;
                break;
            case '/':
                result /= num;
                break;
            case '*':
                result *= num;
                break;
        }
        operator = getchar();
    }
    printf("계산 결과 : %.1f\n", result);
    
    return 0;
}