/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. LENGTH. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* repdigit.c (Chapter 8, page 166) */
/* Checks numbers for repeated digits */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
    bool digit_seen[10] = {false};
    bool digitRepeated[10] = {false};
    bool repeatChecker = false;
    int digit;
    long n;
    
    printf("Enter a number: ");
    scanf("%ld", &n);
    
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            digitRepeated[digit] = true;
            repeatChecker = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    
    if (repeatChecker) {
        printf("Repeated digits are\n");
        for (int i = 0; i < 10; ++i) {
            if (digitRepeated[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
    else
        printf("No repeated digit\n");
    
    return 0;
}
