//
// Created by JediMasterJune on 21. 3. 26..
//

#include <stdio.h>

int main(void)
{
    char ch;
    
    printf("Enter your Alphabetical Phone number : ");
    
    while ((ch = getchar()) != '\n') {
        if ('A' <= ch && ch <= 'Z') {
            printf("%d", (ch - 'A') / 3 + 2);
        }
        else
            putchar(ch);
    }
    
    return 0;
}