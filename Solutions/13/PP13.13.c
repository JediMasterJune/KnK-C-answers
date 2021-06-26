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
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        else if ('a' <= text[i] && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        printf("%c", text[i]);
    }
    printf("\n");
    
    
    return 0;
}