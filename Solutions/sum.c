//
// Created by JediMasterJune on 21. 6. 13..
//

#include <stdio.h>
#include <string.h>

int stringtoint(char* string);

int main(int argc, char* argv[])
{
    int sum = 0;
    /*
    char test[10] = "1234";
    int temp = stringtoint(test);
    printf("%d", temp);
     */
    
    if (argc < 2) {
        puts("Enter the numbers");
        return 1;
    }
    for (int i = 1; i < argc; ++i) {
        sum += stringtoint(argv[i]);
    }
    
    printf("Sum: %d\n", sum);
    return 0;
}

int stringtoint(char* string)
{
    int num = 0;
    int length = strlen(string);
    for (int i = 0; i < length; ++i) {
        int temp = (int) string[i] - '0';
        for (int j = i; j < length - 1; ++j) {
            temp *= 10;
        }
        num += temp;
    }
    
    
    return num;
}


