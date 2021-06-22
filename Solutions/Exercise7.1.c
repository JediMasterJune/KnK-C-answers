//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    //7.1.
    int a, b, c;
    printf("%d %d %d\n", 077, 0x77, 0xABC);
    
    //테스트
    scanf("%d%d%d", &a, &b, &c); // 숫자 사이에 공백이 아닌 문자를 넣으면? -> 스캔이 중지된다.
    printf("%d %d %d\n", a, b, c);
    
    return 0;
}