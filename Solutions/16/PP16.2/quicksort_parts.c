//
//

#include "quicksort_parts.h"

void quicksort(struct part a[], int low, int high)
{
    int middle;
    
    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(struct part a[], int low, int high)
{
    struct part part_element = a[low];
    
    for (;;) {
        while (low < high && part_element.number <= a[high].number) // compares part number
            high--;
        if (low >= high) break;
        a[low++] = a[high]; // changes the structures in the array themselves
        
        while (low < high && a[low].number <= part_element.number)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    
    a[high] = part_element;
    return high;
}