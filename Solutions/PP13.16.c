//
// Created by JediMasterJune on 21. 6. 10..
//

#include <stdio.h>

#define N 100

void messageReversal(char* message);
//void readMessage(int n, char a[n]);

int main(void)
{
    char message[N + 1] = {0};
    //readMessage(N, message);
    gets(message);
    messageReversal(message);
    
    return 0;
}

void messageReversal(char* message)
{
    char* p = message;
    while (*p) p++;
    while (--p >= message) {
        printf("%c", *p);
    }
}

/*
void readMessage(int n, char a[n])
{
    char ch;
    char* p = a;
    while ((ch = getchar()) != '\n' && p < a + n) {
        *(p++) = ch;
    }
}
 */