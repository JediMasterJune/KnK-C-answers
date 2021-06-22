//
// Created by JediMasterJune on 21. 3. 28..
//

#include <stdio.h>

#define MAX_DIGITS 10

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}}; // rows : numbers, colums : segments

char characters[4][MAX_DIGITS * 4]; //rows: 높이, columns : 숫자 하나당 3칸 + 공백 1칸 * 최대 숫자 수

void clearDigitsArray(void);
void processDigit(int digit, int position); // position : 0~MAX_DIGIT-1
void printDigitsArray(void);

int main(void)
{
    char digit;
    int i = 0;
    clearDigitsArray();
    
    while ((digit = getchar()) != '\n') {
        if (i >= MAX_DIGITS) break;
        else if ('0' <= digit && digit <= '9') {
            processDigit((int) digit - '0', i);
            ++i;
        }
    }
    
    printDigitsArray();
    
    return 0;
}

/*********************
 * Name: ClearDigitsArray
 * Stores blank characters into all elements of the 'characters' Array
 */
void clearDigitsArray(void)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 * MAX_DIGITS; ++j) {
            characters[i][j] = ' ';
        }
    }
}

/*********************
 * Name : processDigit
 * Stores the seven-segment representation of digit into a specified position in the 'characters' array
 * @param digit
 * @param position
 */
void processDigit(int digit, int position)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = position * 4, k = 0; j < (position + 1) * 4; ++j, ++k) {
            switch (i) {
                case 0:
                    switch (k) {
                        case 1:
                            if (segments[digit][0] == 1) {
                                characters[i][j] = '_';
                            }
                            break;
                    }
                    break;
                case 1:
                    switch (k) {
                        case 0:
                            if (segments[digit][5] == 1) {
                                characters[i][j] = '|';
                            }
                            break;
                        case 1:
                            if (segments[digit][6] == 1) {
                                characters[i][j] = '_';
                            }
                            break;
                        case 2:
                            if (segments[digit][1] == 1) {
                                characters[i][j] = '|';
                            }
                            break;
                    }
                    break;
                case 2:
                    switch (k) {
                        case 0:
                            if (segments[digit][4] == 1) {
                                characters[i][j] = '|';
                            }
                            break;
                        case 1:
                            if (segments[digit][3] == 1) {
                                characters[i][j] = '_';
                            }
                            break;
                        case 2:
                            if (segments[digit][2] == 1) {
                                characters[i][j] = '|';
                            }
                            break;
                    }
                    break;
            }
            
        }
    }
    
}

/*****************
 * Name: printDigitsArray
 * Displays the rows of the 'characters' array, each on a single line,
 * producing output such as that shown in example.
 */
void printDigitsArray(void)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 * MAX_DIGITS; ++j) {
            printf("%c", characters[i][j]);
        }
        printf("\n");
    }
}