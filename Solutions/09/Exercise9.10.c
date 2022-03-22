//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

#define RANGE (sizeof(arr)/sizeof(arr[0]))

int arrayMax(int n, int a[n]);
double arrayAverage(int n, int a[n]);
int arrayPositiveCount(int n, int a[n]);

int main(void)
{
    int arr[10] = {1, 4, 5, 6, 7, 13, 765, 39, 485, 341};
    printf("Maximum : %d\n", arrayMax(RANGE, arr));
    printf("Average : %f\n", arrayAverage(RANGE, arr));
    printf("Positive Count : %d\n", arrayPositiveCount(RANGE, arr));
    return 0;
}

int arrayMax(int n, int a[n])
{
    int max = a[0];
    for (int i = 0; i < n; ++i) {
        max = a[i] > max ? a[i] : max;
    }
    return max;
}

double arrayAverage(int n, int a[n])
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return (double) sum / n;
}

int arrayPositiveCount(int n, int a[n])
{
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            count++;
        }
    }
    return count;
}
