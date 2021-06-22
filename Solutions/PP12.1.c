//
// Created by JediMasterJune on 21. 6. 10..
//

#include <stdio.h>

#define N 100

void messageReversal(int n, char a[n]);
void readMessage(int n, char a[n]);

int main(void)
{
    char message[N] = {0};
    readMessage(N, message);
    messageReversal(N, message);
    
    return 0;
}

void messageReversal(int n, char a[n])
{
    char* p = a + n - 1;
    while (*p == 0) p--; //조건식에 p--쓰면 조건 만족 안해도 p가 감소한다. 매우 주의
    
    printf("The Reversal is: ");
    while (p >= a) {
        printf("%c", *(p--));
    }
}

void readMessage(int n, char a[n])
{
    char ch;
    char* p = a;
    while ((ch = getchar()) != '\n' && p < a + n) {
        *(p++) = ch;
    }
}