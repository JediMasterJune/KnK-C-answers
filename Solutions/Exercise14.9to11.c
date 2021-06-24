#include <stdio.h>
#include <math.h>

#define CHECK(x, y, n) ((0 <= (x) && (x)<= ((n)-1)) && ((0 <= (y) && (y)<= ((n)-1))))
#define MEDIAN(x, y, z) ((x) > (y) ? ((x) > (z) ? (((y) > (z)) ? (z) : (y)) : (x)) : ((y) > (z) ? (z) : (y)))
#define POLYNOMIAL(x) (3*(pow(x,5))+2*(pow(x,4))-5*(x*x*x)-(x*x)+7*(x)-6)
#define ERROR(...) fprintf(stderr, __VA_ARGS__)
#define PRINT(...) printf(__VA_ARGS__)

int main(void)
{
    int x = 1, y = 2, z = 3, n = 4;
    
    printf("CHECK(1,2,4) = %d\n", CHECK(x, y, n));
    printf("MEDIAN(1,2,3) = %d\n", MEDIAN(x, y, z));
    printf("POLYNOMIAL(1) = %d\n", POLYNOMIAL(x));
    PRINT("TEST%d\n", y);
    ERROR("Test error mesasge: n = %d\n",
          n); //stderr puts the message on the first line or the last line of the program outputs.
    
    return 0;
}