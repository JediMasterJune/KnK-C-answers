//
// Created by JediMasterJune on 21. 6. 11..
//

#include <stdio.h>
#include <string.h>

#define N 100

void removeFilename(char* url);

int main(void)
{
    char url[N + 1];
    printf("Enter your URL: ");
    gets(url);
    removeFilename(url);
    
    puts(url);
    
    return 0;
}


void removeFilename(char* url)
{
    while (*url) url++;
    while ((*url) != '/') url--;
    *url = '\0';
}

