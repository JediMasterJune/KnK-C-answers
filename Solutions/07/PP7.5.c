//
// Created by JediMasterJune on 21. 3. 26..
//

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int score = 0;
    
    printf("문자열 입력 : ");
    while ((ch = getchar()) != '\n') { //괄호 반드시 삽입할 것! 대입 연산자의 우선순위는 낮다!
        ch = toupper(ch);
        switch (ch) {
            case 'Q':
            case 'Z':
                score += 10;
                break;
            case 'J':
            case 'X':
                score += 8;
                break;
            case 'K':
                score += 5;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;
            case 'D':
            case 'G':
                score += 2;
                break;
            default:
                if ('A' <= ch && ch <= 'Z')
                    score++;
        }
    }
    
    printf("점수 = %d\n", score);
    
    return 0;
}