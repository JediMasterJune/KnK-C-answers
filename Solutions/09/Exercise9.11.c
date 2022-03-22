//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>
#include <ctype.h>

#define N (sizeof(grades)/sizeof(grades[0]))

float compute_GPA(char grades[], int n);

int main(void)
{
    char grades[] = {'A', 'A', 'A', 'A', 'B', 'F'};
    printf("average : %f\n", compute_GPA(grades, RANGE));
    return 0;
}

float compute_GPA(char grades[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        grades[i] = toupper(grades[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (grades[i] < 'F') {
            sum += (4 - (grades[i] - 'A'));
        }// unsigned 캐스팅이 부호를 제거해주지 않는다. 어째서? -> 일단 자제하자
    }
    return (float) sum / n;
    
}
