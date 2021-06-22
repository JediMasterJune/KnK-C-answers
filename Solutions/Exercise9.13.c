//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

int evaluatePosition(char board[8][8]);

int main(void)
{
    char board[8][8] = {{'K', 'Q', 'R', 'B', 'B', 'B', 'N', 'B'},
                        {'K', 'Q', 'R', 'B', 'B', 'B', 'N', 'B'},
                        {'K', 'Q', 'R', 'B', 'B', 'B', 'N', 'B'},
                        {'K', 'Q', 'R', 'B', 'B', 'B', 'N', 'B'},
                        {'K', 'Q', 'R', 'B', 'B', 'B', 'N', 'B'},
                        {'k', 'q', 'r', 'b', 'b', 'b', 'n', 'n'},
                        {'k', 'q', 'r', 'b', 'b', 'b', 'n', 'n'},
                        {'k', 'q', 'r', 'b', 'b', 'b', 'n', 'n'}};
    
    printf("The difference is %d\n", evaluatePosition(board));
    
    return 0;
}

int evaluatePosition(char board[8][8])
{
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            switch (board[i][j]) {
                case 'K':
                    sum += 9;
                    break;
                case 'R':
                    sum += 5;
                    break;
                case 'B':
                case 'N':
                    sum += 3;
                    break;
                case 'P':
                    sum += 1;
                    break;
                
                case 'k':
                    sum -= 9;
                    break;
                case 'r':
                    sum -= 5;
                    break;
                case 'b':
                case 'n':
                    sum -= 3;
                    break;
                case 'p':
                    sum -= 1;
                    break;
            }
        }
    }
    return sum;
}
