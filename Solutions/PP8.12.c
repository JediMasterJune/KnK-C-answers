//
// Created by JediMasterJune on 21. 3. 26..
//

#include <stdio.h>
#include <ctype.h>

#define LETTER (sizeof(chCount)/sizeof(chCount[0]))

int main(void)
{
    char ch;
    char chCount['Z' - 'A' + 1] = {['K' - 'A'] = 5};
    int score = 0;
    chCount['Q' - 'A'] = chCount['Z' - 'A'] = 10;
    chCount['J' - 'A'] = chCount['X' - 'A'] = 8;
    //chCount['K' - 'A'] = 5;
    chCount['F' - 'A'] = chCount['H' - 'A'] = chCount['V' - 'A'] = chCount['W' - 'A'] = chCount['Y' - 'A'] = 4;
    chCount['B' - 'A'] = chCount['C' - 'A'] = chCount['M' - 'A'] = chCount['P' - 'A'] = 3;
    chCount['D' - 'A'] = chCount['G' - 'A'] = 2;
    for (int i = 0; i < LETTER; ++i) {
        if (chCount[i] == 0)
            chCount[i] = 1;
    }
    
    printf("문자열 입력 : ");
    while ((ch = getchar()) != '\n') { //괄호 반드시 삽입할 것! 대입 연산자의 우선순위는 낮다!
        ch = toupper(ch);
        score += chCount[ch - 'A'];
    }
    
    printf("점수 = %d\n", score);
    
    return 0;
}