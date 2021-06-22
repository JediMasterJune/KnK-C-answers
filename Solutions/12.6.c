/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* qsort.c (Chapter 9, page 207) */
/* Sorts an array of integers using Quicksort algorithm */

#include <stdio.h>

#define N 10

void quicksort(int a[], int* pLow, int* pHigh);
int* split(int a[], int* pLow, int* pHigh);

int main(void)
{
    int a[N], i;
    
    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    quicksort(a, a, a + N - 1);
    
    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    return 0;
}

void quicksort(int a[], int* pLow, int* pHigh)
{
    int* pMiddle;
    
    if (pLow >= pHigh) return;
    pMiddle = split(a, pLow, pHigh); //첫번째 요소를 partitioning element, pivot으로 설정하고, 중간에 배치한다. (1사이클)
    quicksort(a, pLow, pMiddle - 1); // partitioning element를 기준으로 2개로 분할된 배열들에 대해 재귀적으로 quicksort 실행
    quicksort(a, pMiddle + 1, pHigh);
}

int* split(int a[], int* pLow, int* pHigh)
{
    int part_element = *pLow;
    
    for (;;) { // 1사이클
        while (pLow < pHigh && part_element <= *pHigh) // part_element 보다 작은 값을 발견할 때까지 pHigh가 왼쪽으로 이동
            pHigh--;
        if (pLow == pHigh) break;
        *(pLow++) = *pHigh; // 빈 자리에 박고 pLow를 오른쪽으로 한 칸 이동
        
        while (pLow < pHigh && *pLow <= part_element) //partitioning Element보다 큰 값을 발견할 때까지 pLow가 오른쪽으로 이동
            pLow++;
        if (pLow == pHigh) break;
        *(pHigh--) = *pLow; //발견하면 오른쪽의 빈 자리에 박고 pHigh를 왼쪽으로 한 칸 이동
    }
    
    *pHigh = part_element; // part_element를 마지막 빈 자리 (중간) 에 가져온다.
    return pHigh;
}
