#include <stdio.h>
#include <stdbool.h>

#define DEBUG

enum { NORTH, SOUTH, EAST, WEST } direction;

int main(void)
{
    int x = 0, y = 0;
    
    switch (direction) {
        case EAST:
            x++;
            break;
        case WEST:
            x--;
            break;
        case SOUTH:
            y++;
            break;
        case NORTH:
            y--;
            break;
    }
    
    return 0;
}
