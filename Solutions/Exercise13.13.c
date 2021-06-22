//
// Created by JediMasterJune on 21. 6. 11..
//

#include <stdio.h>
#include <string.h>

#define N 100

void buildIndexURL(const char* domain, char* indexURL);

int main(void)
{
    char domain[N + 1];
    char indexURL[N + 1];
    
    printf("Enter your domain: ");
    gets(domain);
    
    buildIndexURL(domain, indexURL);
    puts(indexURL);
    
    return 0;
}


void buildIndexURL(const char* domain, char* indexURL)
{
    strcpy(indexURL, "https://www.");
    strcat(indexURL, domain);
    strcat(indexURL, "/index.html");
}

