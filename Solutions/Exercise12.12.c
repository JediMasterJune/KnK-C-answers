//
// Created by JediMasterJune on 21. 6. 10..
//
#include <stdio.h>

#define SIZE (sizeof(a)/sizeof(a[0]))

void findTwoLargest(const int* a, int n, int* pLargest, int* pSecondLargest);

int main(void)
{
    int a[] = {1, 3, 435, 76, 538, 942, 123, 214, 59565, 4390};
    int max, secondMax;
    
    findTwoLargest(a, SIZE, &max, &secondMax);
    
    printf("최댓값: %d, 두번째최댓값:%d\n", max, secondMax);
    
    return 0;
    
}

void findTwoLargest(const int* a, int n, int* pLargest, int* pSecondLargest)
{
    int* p;
    *pLargest = *pSecondLargest = *a;
    
    for (p = a + 1; p < a + n; p++) {
        if (*pLargest < *p) {
            *pLargest = *p;
        }
    }
    for (p = a + 1; p < a + n; p++) {
        if (*pSecondLargest < *p) {
            if (*p < *pLargest) {
                *pSecondLargest = *p;
            }
        }
    }
}
