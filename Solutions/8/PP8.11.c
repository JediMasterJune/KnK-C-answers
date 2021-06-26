//
// Created by JediMasterJune on 21. 3. 26..
//

#include <stdio.h>

#define SIZE (sizeof(phoneNum)/sizeof(phoneNum[0]))

int main(void)
{
    char phoneNum[15];
    
    printf("Enter your Alphabetical Phone number : ");
    
    for (int i = 0; i < SIZE; ++i) {
        scanf("%c", &phoneNum[i]);
        if ('A' <= phoneNum[i] && phoneNum[i] <= 'Z') {
            phoneNum[i] = (phoneNum[i] - 'A') / 3 + 2 + '0';
        }
    }
    
    printf("%s\n", phoneNum);
    
    return 0;
}