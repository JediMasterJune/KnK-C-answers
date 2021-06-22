//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>

#define N 100

int main(void)
{
    char string[N] = {0};
    char terminator;
    char* plastAlphabet;
    
    for (int i = 0; i < N; ++i) {
        scanf("%c", &string[i]);
        if (string[i] == '!' || string[i] == '?' || string[i] == '.') {
            terminator = string[i]; //문장부호를 terminator로 설정
            plastAlphabet = string + i - 1; //마지막 알파벳을 가리킨다
            string[i] = 0;
        }
        else if (string[i] == '\n') {
            break;
        }
    }
    
    for (; plastAlphabet >= string; --plastAlphabet) {
        if (*plastAlphabet == ' ' || plastAlphabet == string) { //시작 주소를 가리킬 때 주의
            for (char* inPoint = plastAlphabet + (*plastAlphabet == ' ');
                 *inPoint != 0 && *inPoint != ' '; inPoint++) { //공백이면 한칸 뒤부터, 아니면 그 자리부터 출력
                printf("%c", *inPoint);
            }
            if (*plastAlphabet == ' ') {
                printf(" ");
            }
        }
    }
    printf("%c\n", terminator);
    
    return 0;
}