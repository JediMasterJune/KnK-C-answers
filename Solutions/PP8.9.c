#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE (sizeof(position)/sizeof(position[0]))

int main(void)
{
    int dice;
    int x = 0, y = 0;
    char position[10][10];
    bool blocked[4] = {false};
    
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            position[i][j] = '.';
        }
    }
    
    for (char i = 'A'; i <= 'Z';) {
        int blockCount;
        for (blockCount = 0; blockCount < 4; ++blockCount) {
            if (blocked[blockCount] == false)
                break;
        }
        if (blockCount == 4) {
            printf("Dead end\n");
            break;
        }
        
        if (position[y][x] == '.') {
            position[y][x] = i;
            for (int j = 0; j < 4; ++j) {
                blocked[j] = false;
            }
            i++;
        }
        
        switch (dice = rand() % 4) {
            case 0:
                if (x > 0 && position[y][x - 1] == '.')
                    x--;
                else blocked[0] = true;
                break;
            case 1:
                if (y < SIZE - 1 && position[y + 1][x] == '.')
                    y++;
                else blocked[1] = true;
                break;
            case 2:
                if (y > 0 && position[y - 1][x] == '.')
                    y--;
                else blocked[2] = true;
                break;
            case 3:
                if (x < SIZE - 1 && position[y][x + 1] == '.')
                    x++;
                else blocked[3] = true;
                break;
        }
        
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", position[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
