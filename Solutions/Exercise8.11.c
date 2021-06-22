//
// Created by JediMasterJune on 21. 3. 28..
//

#include <stdio.h>

int main(void)
{
    char checkerBoard[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (((i + j) % 2) == 0) {
                checkerBoard[i][j] = 'B';
            }
            else
                checkerBoard[i][j] = 'R';
        }
        
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%c ", checkerBoard[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}