//
// Created by JediMasterJune on 21. 6. 11..
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define N 100

bool testExtension(const char* fileName, const char* extension);

int main(void)
{
    char filename[N + 1];
    char extension[N + 1];
    bool flag;
    
    printf("Enter your filename: ");
    gets(filename);
    printf("Enter your extension: ");
    flag = testExtension(filename, gets(extension));
    
    if (flag)
        printf("Good\n");
    else
        printf("Meh\n");
    
    return 0;
}


bool testExtension(const char* fileName, const char* extension)
{
    /*
    char fileNameCopy[N + 1];
    char extensionCopy[N + 1];
    strcpy(fileNameCopy, fileName);
    strcpy(extensionCopy, extension);
     */
    
    char* p = fileName;
    while (*p++ != '.');
    
    while (*p) {
        if ((toupper)(*(p++)) != (toupper)(*(extension++))) return false;
    }
    
    //capitalize(p);
    //capitalize(extensionCopy);
    
    //puts(p);
    //puts(extension);
    
    return true;
}

