//
// Created by JediMasterJune on 21. 6. 10..
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define N 100

bool checkPalindrome(int n, char a[n]); //거꾸로 읽어도 같은 문장인 것 (문장부호 무시)
void readMessageOnlyAlpha(int n, char a[n]);

int main(void)
{
    char message[N] = {0};
    printf("Enter your message: ");
    readMessageOnlyAlpha(N, message);
    
    bool checker = checkPalindrome(N, message);
    
    if (checker) {
        printf("Palindrome\n");
    }
    else {
        printf("Nope\n");
    }
    
    return 0;
}

void readMessageOnlyAlpha(int n, char a[n])
{
    char ch;
    char* p = a;
    while ((ch = toupper(getchar())) != '\n' && p < a + n) {
        if (isalpha(ch)) {
            *(p++) = ch;
        }
    }
}

bool checkPalindrome(int n, char a[n]) //거꾸로 읽어도 같은 문장인 것 (문장부호 무시)
{
    char* p = a; // 처음을 가리키는 포인터
    char* q = a + n - 1; //끝을 가리키는 포인터
    while (*q == 0) q--; //q를 문자열의 끝으로 이동
    int k = q - p;
    
    for (p = a; p < a + k / 2; ++p, --q) {
        if (*p != *q) return false;
    }
    
    return true;
}