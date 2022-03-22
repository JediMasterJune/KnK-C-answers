//
//

#include <stdio.h>

struct character {
    int number;
};

int main(void)
{
    struct character luigi;
    luigi.number = 1;
    printf("%d\n", (&luigi)->number);
    return 0;
}