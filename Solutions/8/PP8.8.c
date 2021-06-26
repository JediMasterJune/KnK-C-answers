#include <stdio.h>

#define SIZE (sizeof(matrix)/sizeof(matrix[0]))

int main(void)
{
    int matrix[5][5];
    int rowSum[SIZE] = {0};
    int columnSum[SIZE] = {0};
    int columnMin[SIZE] = {0};
    int columnMax[SIZE] = {0};
    
    //printf("Size of matrix = %zu\n", sizeof(matrix));
    //printf("Size of matrix[0] = %zu\n", sizeof(matrix[0])); //0번째 row의 크기 출력
    
    for (int i = 0; i < SIZE; ++i) {
        printf("enter student %d's scores : ", i + 1);
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &matrix[i][j]); // i번째 row(student)의 점수 입력
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            rowSum[i] += matrix[i][j];
            columnSum[i] += matrix[j][i];
        }
    }
    
    for (int i = 0; i < SIZE; ++i) {
        columnMax[i] = matrix[i][i];
        columnMin[i] = matrix[i][i];
    } //최대, 최소 초기화
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (columnMax[i] < matrix[j][i])//matrix의 i번째 column을 순차 점검
                columnMax[i] = matrix[j][i];
            if (columnMin[i] > matrix[j][i])
                columnMin[i] = matrix[j][i];
        }
    }
    
    printf("student totals : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", rowSum[i]);
    }
    
    printf("\nstudent averages : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%.1f ", (double) rowSum[i] / SIZE);
    }
    
    printf("\nquiz averages : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%.1f ", (double) columnSum[i] / SIZE);
    }
    printf("\n");
    
    printf("quiz high scores : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", columnMax[i]);
    }
    printf("\n");
    
    printf("quiz low scores : ");
    for (int i = 0; i < SIZE; ++i) {
        printf("%d ", columnMin[i]);
    }
    printf("\n");
    
    return 0;
}
