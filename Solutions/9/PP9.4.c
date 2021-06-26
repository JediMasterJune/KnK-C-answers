//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LETTERS 26

void readWord(int counts[LETTERS]);
bool equalArray(int counts1[LETTERS], int counts2[LETTERS]);

int main(void)
{
    int letterCount1[LETTERS] = {0};
    int letterCount2[LETTERS] = {0};
    printf("Enter the first word: ");
    readWord(letterCount1);
    
    printf("Enter the second word : ");
    readWord(letterCount2);
    /*
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            letterCount[ch - 'a']--;
        }
    }
     */
    
    
    /*k
    for (int i = 0; i < LETTERS; ++i) {
        if (letterCount[i]) {
            printf("The words are not anagrams.\n");
            return 0;
        }
    }
     */
    
    if (equalArray(letterCount1, letterCount2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");
    
    return 0;
}

void readWord(int counts[LETTERS])
{
    char ch;
    while ((ch = getchar()) != '\n') {
        ch = tolower(ch);
        if (isalpha(ch)) {
            counts[ch - 'a']++;
        }
    }
    
}

bool equalArray(int counts1[LETTERS], int counts2[LETTERS])
{
    for (int i = 0; i < LETTERS; ++i) {
        if (counts1[i] != counts2[i])
            return false;
    }
    
    return true;
}
