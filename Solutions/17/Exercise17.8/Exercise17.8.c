//
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
    int value;
    struct node* next;
};

struct node* deleteFromList(struct node* list, int n);

int main(void)
{
    
    return 0;
}

struct node* deleteFromList(struct node* list, int n)
{
    struct node* cur;
    for (cur = list; cur != NULL && cur->value != n; cur = cur->next) {
        if (cur->next->value == n) { //중간
            struct node* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            break;
        }
    }
    if (cur == list) { //처음
        list = cur->next;
        free(cur);
    }
    return list;
}
