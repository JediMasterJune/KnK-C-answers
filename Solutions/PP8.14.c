//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>

#define N 100

int main(void)
{
    char string[N] = {0};
    char terminator;
    int lastAlphabet;
    
    for (int i = 0; i < N; ++i) {
        scanf("%c", &string[i]);
        if (string[i] == '!' || string[i] == '?' || string[i] == '.') {
            terminator = string[i];
            lastAlphabet = i - 1;
        }
        else if (string[i] == '\n') {
            break;
        }
    }
    
    for (int i = lastAlphabet; i >= 0; --i) {
        if (string[i] == ' ' || i == 0) {
            for (int j = (i == 0) ? i : i + 1; (string[j] != ' ' && string[j] != terminator); ++j) {
                printf("%c", string[j]);
            }
            if (string[i] == ' ')
                printf(" ");
        }
    }
    printf("%c\n", terminator);
    
    return 0;
}