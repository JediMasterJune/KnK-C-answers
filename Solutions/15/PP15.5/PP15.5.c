//
// Created by JediMasterJune on 21. 6. 8..
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int calculateRPN(stk stack[], int* topP);

int main(void)
{
    stk numStack[STACK_SIZE] = {0};
    //char parenthesesCheck[STACK_SIZE] = {0};
    
    int top = 0;
    int* topP = &top;
    int result;
    
    for (;;) {
        result = calculateRPN(numStack, topP);
        printf("Value of expression: %d\n", result);
    }
    
    return 0;
}

int calculateRPN(stk stack[], int* topP)
{
    makeEmpty(topP);
    int num1, num2;
    int result;
    char ch;
    printf("Enter an RPN expression: ");
    while ((ch = getchar()) != '=') {
        if ('0' <= ch && ch <= '9') {
            push(stack, topP, ch - '0');
        }
        else {
            switch (ch) {
                case '+':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 + num2;
                    push(stack, topP, result);
                    break;
                case '-':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 - num2;
                    push(stack, topP, result);
                    break;
                case '/':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 / num2;
                    push(stack, topP, result);
                    break;
                case '*':
                    num2 = pop(stack, topP);
                    num1 = pop(stack, topP);
                    result = num1 * num2;
                    push(stack, topP, result);
                    break;
                default:
                    if (ch != '\n' && ch != ' ')
                        exit(EXIT_SUCCESS);
            }
        }
    }
    return result;
}
