//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE (sizeof(lastName)/sizeof (lastName[0]))

int main(void)
{
    //char nameSpace;
    char firstLetter;
    char lastName[20] = {0};
    //bool isLastName = false;
    
    printf("영어 이름 입력 : ");
    scanf(" %c", &firstLetter);
    
    while (getchar() != ' ');
    for (int i = 0; i < SIZE; ++i) {
        lastName[i] = getchar();
        //scanf("%c", &lastName[i]);
        if (lastName[i] != '\n')
            printf("%c", lastName[i]);
        else
            break;
    }
    
    printf(", %c.\n", firstLetter);
    
    return 0;
}