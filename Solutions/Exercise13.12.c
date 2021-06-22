//
// Created by JediMasterJune on 21. 6. 11..
//

#include <stdio.h>
#include <string.h>

#define N 100

void getExtension(const char* fileName, char* extension);

int main(void)
{
    char file[N + 1];
    char extension[N + 1];
    
    printf("Enter the file name: ");
    gets(file);
    
    getExtension(file, extension);
    
    puts(extension);
    
    return 0;
}


void getExtension(const char* fileName, char* extension)
{
    char* p = fileName + strlen(fileName); // null 문자까지 이동
    while (*p != '.' && p > fileName) p--;
    
    strcpy(extension, (*p == '.') ? p + 1 : "");
}

