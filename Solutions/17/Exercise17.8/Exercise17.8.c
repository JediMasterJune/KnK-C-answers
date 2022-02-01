//
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    struct node* stack = NULL;
    stack = push(stack, 1);
    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = push(stack, 4);
    stack = push(stack, 5);
    pop(stack);
    pop(stack);
    for (struct node* i = stack; i != NULL; i = i->next) {
        printf("%d\n", i->value);
    }
    
    return 0;
}
