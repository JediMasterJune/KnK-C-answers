//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int arr[16] = {0};
    int horizonSum[4] = {0};
    int verticalSum[4] = {0};
    int diagonalSum[2] = {0}; // diagonal : 대각선의
    int count = 0;
    
    printf("Enter the numbers from 1 to 16 in any order : ");
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) // i is from 0 to 15
    {
        scanf("%d", arr + i);
    }
    
    for (int i = 0; i < sizeof(arr) / sizeof(int) / 4; ++i) // i is from 0 to 3
    {
        for (int j = 0; j < sizeof(arr) / sizeof(int) / 4; ++j)
        {
            horizonSum[i] += arr[4 * i + j]; //i : 행, j : 열
        }
    }
    
    for (int i = 0; i < sizeof(arr) / sizeof(int) / 4; ++i)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(int) / 4; ++j)
        {
            verticalSum[i] += arr[i + 4 * j];
        }
    }
    
    for (int i = 0; i < 2; ++i) // i is 0 to 1
    {
        for (int j = 0; j < sizeof(arr) / sizeof(int) / 4; ++j)
        {
            if (i == 0)
                diagonalSum[i] += arr[(sizeof(arr) / sizeof(int) / 4 + 1) * j]; //0 5 10 15 at 0, 3 6 9 12 at 1
            else
                diagonalSum[i] += arr[3 * (j + 1)];
        }
    }
    
    for (int i = 0; i < sizeof(arr) / sizeof(int) / 4; ++i)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(int) / 4; j++)
        {
            printf("%d ", arr[count]);
            count++;
        }
        printf("\n");
    }
    
    printf("Horizontal sums : ");
    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", horizonSum[i]);
    }
    printf("\n");
    
    printf("Vertical sums : ");
    for (int i = 0; i < 4; ++i)
    {
        printf("%d ", verticalSum[i]);
    }
    printf("\n");
    
    printf("Diagonal sums : ");
    for (int i = 0; i < 2; ++i)
    {
        printf("%d ", diagonalSum[i]);
    }
    printf("\n");
    
    return 0;
}