//
// Created by JediMasterJune on 21. 5. 21..
//

#include <stdio.h>

int powerInt(int x, int n);

int main(void)
{
    int x, n;
    printf("Enter x, n: ");
    scanf("%d%d", &x, &n);
    printf("The result is %d\n", powerInt(x, n));
    
    
    return 0;
}

int powerInt(int x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0) {
        return powerInt(x, n / 2) * powerInt(x, n / 2);
    }
    else
        return x * powerInt(x, n - 1);
}
