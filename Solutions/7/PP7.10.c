//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char letter;
    int vowels;
    
    while ((letter = getchar()) != '\n') {
        letter = toupper(letter);
        switch (letter) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowels++;
                break;
        }
    }
    printf("모음 수 : %d\n", vowels);
    
    return 0;
}