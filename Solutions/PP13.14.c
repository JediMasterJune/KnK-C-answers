//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LETTERS 26
#define N 100

bool areAnagrams(const char* word1, const char* word2);

int main(void)
{
    char word1[N + 1];
    char word2[N + 1];
    
    printf("Enter two words: ");
    scanf("%s", word1);
    scanf("%s", word2);
    
    if (areAnagrams(word1, word2))
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");
    
    return 0;
}

bool areAnagrams(const char* word1, const char* word2)
{
    char letterCount[LETTERS] = {0};
    
    while (*word1) {
        if (isalpha(*word1)) {
            letterCount[toupper(*word1) - 'A']++;
        }
        word1++;
    }
    
    while (*word2) {
        if (isalpha(*word2)) {
            letterCount[toupper(*word2) - 'A']--;
        }
        word2++;
    }
    
    for (int i = 0; i < LETTERS; ++i) {
        if (letterCount[i]) return false;
    }
    
    return true;
}