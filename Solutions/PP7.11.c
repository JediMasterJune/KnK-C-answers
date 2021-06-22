//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    char nameSpace;
    char firstLetter;
    bool lastName = false;
    
    printf("영어 이름 입력 : ");
    scanf(" %c", &firstLetter);
    
    while ((nameSpace = getchar()) != '\n') {
        if (lastName) {
            if (nameSpace != ' ') {
                putchar(nameSpace);
            }
        }
        if (nameSpace == ' ') {
            lastName = true;
        }
    }
    
    printf(", %c.\n", firstLetter);
    
    return 0;
}