//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node* next;
};


void deleteFromList(struct node** p_list, int n);

int main(void)
{
    
    return 0;
}

void deleteFromList(struct node** p_list, int n)
{
    struct node* cur;
    for (cur = *p_list; cur != NULL && cur->value != n; cur = cur->next) {
        if (cur->next->value == n) { //중간
            struct node* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            break;
        }
    }
    if (cur == *p_list) { //처음
        *p_list = cur->next;
        free(cur);
    }
//    return p_list;
}
