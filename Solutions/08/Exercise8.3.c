//
// Created by JediMasterJune on 21. 3. 28..
//

#include <stdio.h>
#include <stdbool.h>

#define SIZE (sizeof(weekend)/sizeof(weekend[0]))

int main(void)
{
    bool weekend[7] = {[0]=true, [6]=true};
    for (int i = 0; i < SIZE; ++i) {
        printf("%p ", &weekend[i]);
        //printf("%d ", weekend[i]);
    }
    printf("size of bool is : %zu\n", sizeof(bool));
    
    return 0;
}