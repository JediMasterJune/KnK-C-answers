//
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void stackUnderflow(void)
{
    printf("Stack Underflow~!\n");
    exit(EXIT_FAILURE);
}

void stackOverflow(void)
{
    printf("Stack Overflow~!\n");
    exit(EXIT_FAILURE);
}

void makeEmpty(int* topP)
{
    *(topP) = 0;
}

bool isEmpty(stk stack[], int* topP)
{
    return (*topP == 0);
}

bool isFull(stk stack[], int* topP)
{
    return (*topP == STACK_SIZE - 1);
}

void push(stk stack[], int* topP, stk num)
{
    if (!isFull(stack, topP)) {
        stack[(*topP)++] = num;
    }
    else {
        stackOverflow();
    }
}

stk pop(stk stack[], int* topP)
{
    if (!isEmpty(stack, topP)) {
        /*
        char temp = stack[*topP];
        stack[(*topP)--] = 0;
        return temp;
         */ // 실제로 배열을 비우지 않아도 된다.
        return stack[--(*topP)]; //StackPointer를 1 감소시킨 후에 리턴
    }
    else {
        stackUnderflow();
    }
}
