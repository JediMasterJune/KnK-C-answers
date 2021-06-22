//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>

#define N 50

int computeVowelCount(const char* sentence);

int main(void)
{
    //char letter;
    int vowels;
    char string[N + 1];
    gets(string);
    
    vowels = computeVowelCount(string);
    
    printf("모음 수 : %d\n", vowels);
    
    return 0;
}

int computeVowelCount(const char* sentence)
{
    int vowels = 0;
    while (*sentence) {
        switch (toupper(*sentence)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
        }
        sentence++;
    }
    return vowels;
}

