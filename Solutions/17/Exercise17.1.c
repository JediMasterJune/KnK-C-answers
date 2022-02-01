//
//

#include <stdio.h>
#include <stdlib.h>

void* myMalloc(size_t n);

int main(void)
{
    int* test = myMalloc(sizeof(*test));
    *test = 8;
    printf("%d\n", *test);
    return 0;
}

void* myMalloc(size_t n)
{
    void* target = malloc(n);
    if (target == NULL) {
        printf("Unable to allocate space\n");
        exit(EXIT_FAILURE);
    }
    return target;
}
