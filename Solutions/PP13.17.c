//
// Created by JediMasterJune on 21. 6. 10..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

bool checkPalindrome(char* message); //거꾸로 읽어도 같은 문장인 것 (문장부호 무시)
void readMessageOnlyAlpha(char* message);

int main(void)
{
    char message[N + 1] = {0};
    printf("Enter your message: ");
    readMessageOnlyAlpha(message);
    
    bool checker = checkPalindrome(message);
    
    if (checker) {
        printf("Palindrome\n");
    }
    else {
        printf("Nope\n");
    }
    
    return 0;
}

void readMessageOnlyAlpha(char* message)
{
    char ch;
    char* p = message;
    while ((ch = toupper(getchar())) != '\n') {
        if (p > message + N - 1) break;
        else if (isalpha(ch)) {
            *(p++) = ch;
        }
    }
    *p = '\0';
}

bool checkPalindrome(char* message) //거꾸로 읽어도 같은 문장인 것 (문장부호 무시)
{
    char* p = message; // 처음을 가리키는 포인터
    char* q = message; //끝을 가리키는 포인터
    while (*q) q++; //q를 문자열의 끝으로 이동
    int k = q-- - p; //k = 문자열 길이 -1
    
    for (p = message; p < message + k / 2; ++p, --q) {
        if (*p != *q) return false;
    }
    
    return true;
}