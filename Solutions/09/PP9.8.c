//
// Created by JediMasterJune on 21. 5. 21..
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int rollDice(void);
bool gameofCraps(int n, int point);


int main(void)
{
    srand((unsigned) clock(NULL));
    int win = 0, lose = 0;
    char choice = 'y';
    
    while (choice == 'y') {
        if (gameofCraps(0, 0)) {
            printf("You win!\n");
            win++;
        }
        else {
            printf("You lose!\n");
            lose++;
        }
        printf("Play again?");
        for (;;) {
            scanf("%c", &choice);
            if (choice == 'y' || choice == 'n')
                break;
        }
        printf("\n");
    }
    
    printf("Wins : %d, Loses : %d\n", win, lose);
    
    return 0;
}

int rollDice(void)
{
    int a = rand() % 6 + 1;
    int b = rand() % 6 + 1;
    return a + b;
}

bool gameofCraps(int n, int point)
{
    
    //int dice1 = rollDice(), dice2 = rollDice();
    int sum = rollDice();
    printf("You rolled %d\n", sum);
    
    if (n == 0) {
        if (sum == 7 || sum == 11) {
            return true;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            return false;
        }
        else {
            point = sum;
            printf("Your point is %d\n", point);
        }
    }
    else {
        if (sum == point) {
            return true;
        }
        else if (sum == 7) {
            return false;
        }
    }
    
    return gameofCraps(n + 1, point);
}

