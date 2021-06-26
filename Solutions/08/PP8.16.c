//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>
#include <ctype.h>

#define LETTERS 26

int main(void)
{
    int letterCount[LETTERS] = {0};
    char ch;
    
    printf("Enter the first word : ");
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            letterCount[ch - 'a']++;
        }
    }
    
    printf("Enter the second word : ");
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            letterCount[ch - 'a']--;
        }
    }
    
    for (int i = 0; i < LETTERS; ++i) {
        if (letterCount[i]) {
            printf("The words are not anagrams.\n");
            return 0;
        }
    }
    
    printf("The words are anagrams.\n");
    
    return 0;
}