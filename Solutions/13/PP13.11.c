//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 300

double computeAverageWordLength(const char* sentence);
void readSentence(char*);

int main(void)
{
    char sentence[N + 1];
    readSentence(sentence);
    
    printf("평균 단어 길이 : %f\n", computeAverageWordLength(sentence));
    
    return 0;
}


void readSentence(char* string)
{
    bool spaceCheck;
    char ch;
    char* p = string;
    
    while ((ch = getchar()) == ' '); // 초기 공백 제거
    
    do {
        if (ch == ' ') {
            if (!spaceCheck) {
                *p++ = ch;
                spaceCheck = true;
            }
        } // 중간 공백은 1개만 허용
        else {
            *p++ = ch;
            spaceCheck = false;
        }
    } while ((ch = getchar()) != '\n');
    
    if (*(p - 1) == ' ') *(p - 1) = '\0'; //끝 공백 제거
    else *p = '\0';
    
}

double computeAverageWordLength(const char* sentence)
{
    int sum = 0;
    int wordcount = 1;
    while (*sentence) {
        if (*sentence == ' ') {
            wordcount++;
            sentence++;
            continue;
        }
        sum++;
        sentence++;
    }
    return (double) sum / wordcount;
}
