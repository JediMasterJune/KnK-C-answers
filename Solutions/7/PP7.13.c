//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int sum = 0;
    int wordcount = 1;
    bool spaceCheck = false;
    char ch;
    
    while ((ch = getchar()) != '\n') {
        if (ch == ' ') {
            if (!spaceCheck) {
                spaceCheck = true;
                wordcount++;
            }
        }
        else {
            sum++;
            spaceCheck = false;
        }
    }
    printf("평균 단어 길이 : %f\n", (double) sum / wordcount);
    
    
    return 0;
}