//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* create_array(int n, int initial_value);

int main(void)
{
    int* arr = create_array(10, 5);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int* create_array(int n, int initial_value)
{
    int* new_arr = calloc(n, sizeof(*new_arr));
    if (new_arr == NULL) {
        return new_arr;
    }
    for (int i = 0; i < n; ++i) {
        new_arr[i] = initial_value;
    }
    return new_arr;
}
