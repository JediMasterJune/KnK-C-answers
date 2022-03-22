//
//

#include <stdio.h>
#include "../Exercise17.8/stack.h"

int count_occurences(struct node* list, int n);
struct node* findLast(struct node* list, int n);

int main(void)
{
    struct node* list = NULL;
    for (int i = 0; i < 10; ++i) {
        list = push(list, 5);
    }
    
    printf("occurences of %d: %d\n", 5, count_occurences(list, 5));
    printf("The last node with %d: 0x%p\n", 5, findLast(list, 5));
    
    return 0;
}

int count_occurences(struct node* list, int n)
{
    int count = 0;
    for (struct node* cur = list; cur; cur = cur->next) {
        if (cur->value == n) count++;
    }
    return count;
}

struct node* findLast(struct node* list, int n)
{
    struct node* target = NULL;
    for (struct node* cur = list; cur; cur = cur->next) {
        if (cur->value == n) target = cur;
    }
    return target;
}
