#include <stdio.h>

#define SIZE (sizeof(matrix)/sizeof(matrix[0]))

int main(void)
{
    int matrix[5][5];
    int rowSum[SIZE] = {0};
    int columnSum[SIZE] = {0};
    
    printf("Size of matrix = %zu\n", sizeof(matrix));
    printf("Size of matrix[0] = %zu\n", sizeof(matrix[0]));
    
    for (int i = 0; i < SIZE; ++i) {
        printf("enter row %d : ", i + 1);
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            rowSum[i] += matrix[i][j];
            columnSum[i] += matrix[j][i];
        }
    }
    
    printf("row totals : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", rowSum[i]);
    }
    printf("\ncolumn totals : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", columnSum[i]);
    }
    printf("\n");
    
    return 0;
}
