//
// Created by JediMasterJune on 21. 6. 13..
//

#include <stdio.h>
#include <string.h>

#define MAX_LETTER 20

int main(void)
{
    char smallest[MAX_LETTER + 1];
    char largest[MAX_LETTER + 1];
    char string[MAX_LETTER + 1];
    
    gets(string);
    strcpy(smallest, string);
    strcpy(largest, string);
    
    while (strlen(string) != 4) {
        if (strcmp(string, smallest) < 0) {
            strcpy(smallest, string);
        }
        else if (strcmp(string, largest) > 0) {
            strcpy(largest, string);
        }
        gets(string);
    }
    
    printf("The first word is ");
    puts(smallest);
    
    printf("The last word is ");
    puts(largest);
    
    return 0;
}