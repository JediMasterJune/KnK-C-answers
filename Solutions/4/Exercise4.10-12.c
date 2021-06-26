//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>

int main(void)
{
    int i, j, k;
    
    // number 10
    i = 6;
    j = i += i;
    printf("%d %d\n", i, j); //a
    
    i = 5;
    j = (i -= 2) + 1;
    printf("%d %d\n", i, j); //b
    
    i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d\n", i, j); //c
    
    i = 2, j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d\n", i, j); //d
    
    //number11
    i = 1;
    printf("%d ", i++ - 1);
    printf("%d\n", i); //a
    
    i = 10, j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d\n", i, j); //b
    
    i = 7, j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d\n", i, j); //c
    
    i = 3, j = 4, k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d\n", i, j, k); //d
    
    //number12
    i = 5;
    j = ++i * 3 - 2;
    printf("%d %d\n", i, j); //a
    
    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d\n", i, j); //b
    
    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j); //c
    
    i = 7;
    j = 3 + --i * 2;
    printf("%d %d\n", i, j); //d
    
    return 0;
}