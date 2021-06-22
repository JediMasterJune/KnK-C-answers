#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10

void generateRandomWalk(char walk[10][10]);
void printArray(char walk[10][10]);

int main(void)
{
    char position[10][10];
    generateRandomWalk(position);
    printArray(position);
    
    return 0;
}

void generateRandomWalk(char walk[10][10])
{
    int dice;
    int x = 0, y = 0;
    bool blocked[4] = {false}; //네 방향이 막혔는지 체크
    
    srand((unsigned) time(NULL));
    
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            walk[i][j] = '.';
        }
    }
    //모든 요소를 '.' 으로 채워넣기
    
    for (char i = 'A'; i <= 'Z';) {
        int blockChecker;
        for (blockChecker = 0; blockChecker < 4; ++blockChecker) {
            if (blocked[blockChecker] == false)
                break;
        } //한 군데라도 뚫려있으면 break
        if (blockChecker == 4) {
            printf("Dead end\n");
            break;
        } //모두 다 막혔을 경우 데드엔드 출력하고 for문 탈출
        
        if (walk[y][x] == '.') { //주변이 막혀 제자리에서 멈춰있는 경우를 위해 비어있는지 체크한다
            walk[y][x] = i;
            for (int j = 0; j < 4; ++j) {
                blocked[j] = false;
            }
            i++;
        } //빈 자리를 문자로 채워넣고 블록카운트 초기화, 문자 바꾸기
        
        switch (dice = rand() % 4) { //0~3 주사위 던지기
            case 0:
                if (x > 0 && walk[y][x - 1] == '.') //옮겨갈 자리가 유효한지 체크
                    x--; //이동한다.
                else blocked[0] = true; //막혔으면 blocked 처리
                break;
            case 1:
                if (y < SIZE - 1 && walk[y + 1][x] == '.')
                    y++;
                else blocked[1] = true;
                break;
            case 2:
                if (y > 0 && walk[y - 1][x] == '.')
                    y--;
                else blocked[2] = true;
                break;
            case 3:
                if (x < SIZE - 1 && walk[y][x + 1] == '.')
                    x++;
                else blocked[3] = true;
                break;
        }
        
    }
}

void printArray(char walk[10][10])
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}
