//
// Created by JediMasterJune on 21. 6. 8..
//

#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

bool isEmpty(char stack[], int* topP);
bool isFull(char stack[], int* topP);
void push(char stack[], int* topP, char ch);
char pop(char stack[], int* topP);

bool stackUnderflow = false;
bool stackOverflow = false;

int main(void)
{
    char stringStack[STACK_SIZE] = {0};
    //char parenthesesCheck[STACK_SIZE] = {0};
    int top = 0;
    int* topP = &top;
    char ch;
    
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case '(':
            case '{':
                push(stringStack, topP, ch);
                break;
            case ')':
                if (stringStack[top - 1] == '(') { //push 후 top이 increment 된 상태이므로, 스택에서 데이터가 저장된 끝 위치는 top-1
                    pop(stringStack, topP);
                    break;
                }
            case '}':
                if (stringStack[top - 1] == '{') {
                    pop(stringStack, topP);
                    break;
                }
        }
    }
    
    if (isEmpty(stringStack, topP) && !stackUnderflow && !stackOverflow) {
        printf("The parentheses/braces are correctly nested.\n");
    }
    else {
        printf("Nah\n");
    }
    
    return 0;
}

bool isEmpty(char stack[], int* topP)
{
    return (*topP == 0);
}

bool isFull(char stack[], int* topP)
{
    return (*topP == STACK_SIZE - 1);
}

void push(char stack[], int* topP, char ch)
{
    if (!isFull(stack, topP)) {
        stack[(*topP)++] = ch;
    }
    else {
        stackOverflow = true;
    }
}

char pop(char stack[], int* topP)
{
    if (!isEmpty(stack, topP)) {
        /*
        char temp = stack[*topP];
        stack[(*topP)--] = 0;
        return temp;
         */ // 실제로 배열을 비우지 않아도 된다.
        return stack[(*topP)--];
    }
    else {
        stackUnderflow = true;
        return 0;
    }
}
