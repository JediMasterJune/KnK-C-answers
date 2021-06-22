//
// Created by JediMasterJune on 21. 5. 21..
//

#include <stdio.h>

void selectionSort(int n, int arr[n]);

int main(void)
{
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    selectionSort(n, arr);
    printf("Sorted: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void selectionSort(int n, int arr[n])
{
    int index = 0;
    int max = arr[index];
    int temp = arr[n - 1];
    
    for (int i = 1; i < n; ++i) {
        if (max < arr[i]) {
            max = arr[i];
            index = i;
        }
    }
    
    arr[n - 1] = max;
    arr[index] = temp;
    if (n > 1)
        selectionSort(n - 1, arr);
}
