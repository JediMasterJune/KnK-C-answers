//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>

#define N 80

int main(void)
{
    char text[N];
    int length;
    int shift;
    
    printf("Enter message to be encrypted : ");
    for (int i = 0; i < N; ++i) {
        scanf("%c", &text[i]);
        if (text[i] == '\n') {
            length = i;
            break;
        }
    }
    
    printf("Enter shift amount : ");
    scanf("%d", &shift);
    
    for (int i = 0; i < length; ++i) {
        if ('A' <= text[i] && text[i] <= 'Z') {
            /*
            if (text[i] + shift <= 'Z')
                text[i] += shift;
            else
                text[i] = text[i] - ('Z' - 'A' + 1) + shift;
                */
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        else if ('a' <= text[i] && text[i] <= 'z') {
            /*
            if (text[i] + shift <= 'z')
                text[i] += shift;
            else
                text[i] = text[i] - ('z' - 'a' + 1) + shift;
                */
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        printf("%c", text[i]);
    }
    printf("\n");
    
    
    return 0;
}