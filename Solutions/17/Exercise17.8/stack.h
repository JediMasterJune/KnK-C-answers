//
//

#ifndef PRACTICE_STACK_H
#define PRACTICE_STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

typedef int stk;
struct node {
    stk value;
    struct node* next;
};

bool isEmpty(struct node* stack);
//bool isFull(stk stack[], int* topP);
void makeEmpty(struct node* stack);
struct node* push(struct node* stack, stk num);
stk pop(struct node* stack);
void stackUnderflow(void);
void stackOverflow(void);

#endif //PRACTICE_STACK_H
