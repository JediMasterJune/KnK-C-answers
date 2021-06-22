#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    // getchar method
    /*
    char string;
    printf("Enter message : ");
    while ((string = getchar()) != '\n') {
        string = toupper(string);
        switch (string) {
            case 'A':
                string = '4';
                break;
            case 'B':
                string = '8';
                break;
            case 'E':
                string = '3';
                break;
            case 'I':
                string = '1';
                break;
            case 'O':
                string = '0';
                break;
            case 'S':
                string = '5';
                break;
        }
        printf("%c", string);
    }
    printf("!!!!!!!!!!\n");
    */
    
    char string[N];
    int enterTime;
    
    printf("Enter message : ");
    //scanf("%s", string);
    
    for (int i = 0;; i++) {
        scanf("%c", &string[i]);
        if (string[i] == '\n') {
            enterTime = i;
            break;
        }
        
        string[i] = toupper(string[i]);
        switch (string[i]) {
            case 'A':
                string[i] = '4';
                break;
            case 'B':
                string[i] = '8';
                break;
            case 'E':
                string[i] = '3';
                break;
            case 'I':
                string[i] = '1';
                break;
            case 'O':
                string[i] = '0';
                break;
            case 'S':
                string[i] = '5';
                break;
        }
        
    }
    
    for (int i = 0; i < enterTime; ++i) {
        printf("%c", string[i]);
    }
    printf("!!!!!!!!!!\n");
    
    return 0;
}
