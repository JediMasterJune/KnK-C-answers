//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sum(int (* f)(int), int start, int end);
int doubling(int n);

int main(void)
{
    printf("%d\n", sum(doubling, 1, 10));
    
    return 0;
}

int sum(int (* f)(int), int start, int end)
{
    int result = 0;
    
    for (int i = start; i <= end; ++i) {
        result += f(i);
    }
    
    return result;
}

int doubling(int n)
{
    return 2 * n;
}

