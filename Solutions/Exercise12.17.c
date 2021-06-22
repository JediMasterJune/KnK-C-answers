//
// Created by JediMasterJune on 21. 6. 10..
//
#include <stdio.h>

#define NUM_ROW 5
#define NUM_COL 10

int sumTwoDimensionalArray(const int (* a)[NUM_COL], int n); // 2차원 배열이 decay되는 포인터형 = 길이가 column 개수인 1차원배열을 가리키는 포인터형

int main(void)
{
    int arr[NUM_ROW][NUM_COL] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    };
    
    printf("The sum of the array: %d\n", sumTwoDimensionalArray(arr, NUM_ROW * NUM_COL));
    
    return 0;
    
}


int sumTwoDimensionalArray(const int (* a)[NUM_COL], int n)
{
    int* p;
    int sum = 0;
    
    for (p = *a; p < *a + n; p++) {
        sum += *p;
    }
    
    return sum;
    
}
