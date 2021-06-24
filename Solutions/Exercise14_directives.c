#include <stdio.h>

#define CUBE(x) (x)*(x)
#define LESS100(x,y) ((x)*(y) < (100))
#define RE4(n) ((n)%(4))

int main(void)
{
    int x = 10;
    int y = CUBE(x);
    int n = 5;

    printf("x = %d, y = %d, n = %d\n",x,y,n);
    printf("Is x*n less than 100? -> %d\n",LESS100(x,n));
    printf("n %% 4 = %d\n",RE4(n));

    return 0;
}
