//
//

#include <stdio.h>

#define NAME_LEN 32

struct part {
    int number;
    char name[NAME_LEN + 1];
    int onHand;
    struct part* next;
};

void printPart(struct part* p_part);

int main(void)
{
    printPart(&(struct part) {1, "luigi", 5});
    return 0;
}

void printPart(struct part* p_part)
{
    printf("Part number: %d\n", p_part->number);
    printf("Part name: %s\n", p_part->name);
    printf("Quantity on hand: %d\n", p_part->onHand);
}
