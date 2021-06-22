//
// Created by JediMasterJune on 21. 6. 10..
//
#include <stdio.h>

#define N 5

void makeIdentity(int n, int* a);

int main(void)
{
    int a[N][N];
    makeIdentity(N, a);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}

void makeIdentity(int n, int* a)
{
    int* p;
    int count = n;
    for (p = a; p < a + n * n; p++) {
        if (count == n) { // 0을 n번 찍었을 경우
            *p = 1;
            count = 0;
        }
        else {
            *p = 0;
            count++;
        }
    }
}
