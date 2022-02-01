//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle* p;

int main(void)
{
    p = malloc(sizeof(struct rectangle));
    p->upper_left = (struct point) {10, 25};
    p->lower_right = (struct point) {20, 15};
    printf("%d %d\n", p->upper_left.x, p->upper_left.y);
    printf("%d %d\n", p->lower_right.x, p->lower_right.y);
    return 0;
}
