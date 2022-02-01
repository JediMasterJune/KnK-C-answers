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

void makeEmpty(struct node* stack)
{
    while (stack != NULL) {
        struct node* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

bool isEmpty(struct node* stack)
{
    return (stack == NULL);
}

//struct node* isFull(struct node* stack)
//{
//}

struct node* push(struct node* stack, stk num)
{
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node != NULL) {
        struct node* cur = stack;
        if (cur == NULL) {
            cur = new_node;
            stack = cur;
        }
        else {
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = new_node;
            cur = cur->next;
        }
        cur->next = NULL;
        cur->value = num;
    }
    else {
        stackOverflow();
    }
    return stack;
}

stk pop(struct node* stack)
{
    if (!isEmpty(stack)) {
        /*
        char temp = stack[*topP];
        stack[(*topP)--] = 0;
        return temp;
         */ // 실제로 배열을 비우지 않아도 된다.
        while (stack->next->next != NULL) {
            stack = stack->next;
        }
        stk num = stack->next->value;
        free(stack->next);
        stack->next = NULL;
        return num;
    }
    else {
        stackUnderflow();
    }
}
