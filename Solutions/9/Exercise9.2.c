//
// Created by JediMasterJune on 21. 5. 18..
//

#include <stdio.h>

int check(int x, int y, int n);

int main(void)
{
    check(2, 5, 10);
    return 0;
}

int check(int x, int y, int n)
{
    if (0 <= x && x < n) {
        if (0 <= y && y < n) {
            return 1;
        }
    }
    else return 0;
}
