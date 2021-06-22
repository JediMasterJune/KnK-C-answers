//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>

#define NUM_WORDS 30
#define NUM_CHAR 20

int main(void)
{
    //char string[N] = {0};
    char words[NUM_WORDS][NUM_CHAR];
    char terminator;
    char* p;
    
    int i;
    //int lastAlphabet;
    
    for (i = 0; i < NUM_WORDS; ++i) {
        scanf("%s", words[i]);
        p = words[i];
        
        while (*p != '\0' && *(p) != '!' && *(p) != '?' && *(p) != '.') p++; //null 문자 or 마침표 있는 곳까지 이동
        
        if (*p == '!' || *p == '?' || *p == '.') {
            terminator = *p;
            *p = '\0';
            break;
        }
    }
    
    for (int j = i; j >= 0; --j) {
        printf(" %s", words[j]);
    }
    
    printf("%c\n", terminator);
    
    return 0;
}