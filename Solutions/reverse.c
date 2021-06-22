//
// Created by JediMasterJune on 21. 6. 13..
//

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Enter at least 1 argument.\n");
        return -1;
    }
    
    for (int i = argc; i > 0; --i) { //argc 적극 활용하자!
        printf(argv[i]);
        printf(" ");
    }
    
    printf("\n");
    
    return 0;
}