//
// Created by JediMasterJune on 21. 2. 24..
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define N 200

void readName(char* string);
void reverseName(char* name);

int main(void)
{
    //bool lastName = false;
    //char firstName[N + 1];
    //char lastName[N + 1];
    char name[N + 1];
    
    printf("영어 이름 입력 : ");
    readName(name);
    puts(name);
    //scanf(" %c", &firstLetter);
    
    reverseName(name);
    
    puts(name);
    
    return 0;
}

void readName(char* string)
{
    int spacecount = 0;
    char ch;
    char* p = string;
    
    while ((ch = getchar()) == ' ');
    
    do {
        if (p > string + N - 1) break;
        else if (ch == ' ') {
            spacecount++;
        }
        else spacecount = 0;
        
        if (spacecount <= 1) {
            *p++ = ch;
        }
    } while ((ch = getchar()) != '\n');
    if (*(p - 1) == ' ') *(p - 1) = '\0';
    *p = '\0';
}

void reverseName(char* name)
{
    char firstname;
    char lastname[N + 1];
    
    char* p = name;
    
    while (*p++ != ' '); //처음으로 나타나는 공백 검사
    
    firstname = name[0];
    strcpy(lastname, p);
    sprintf(name, "%s, %c.", lastname, firstname);
}
