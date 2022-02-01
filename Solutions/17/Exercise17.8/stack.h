//
//

#ifndef PRACTICE_STACK_H
#define PRACTICE_STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

typedef int stk;

bool isEmpty(stk stack[], int* topP);
bool isFull(stk stack[], int* topP);
void makeEmpty(int* topP);
void push(stk stack[], int* topP, stk num);
stk pop(stk stack[], int* topP);
void stackUnderflow(void);
void stackOverflow(void);

#endif //PRACTICE_STACK_H
