/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. RANGE. King                                         *
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
    //bool digitRepeated[10] = {false};
    //bool repeatChecker = false;
    int digit;
    long n;
    
    while (1) {
        int digit_seen[10] = {0};
        printf("Enter a number: ");
        scanf("%ld", &n);
        if (n <= 0)
            break;
        
        while (n > 0) {
            digit = n % 10;
            digit_seen[digit]++;
            n /= 10;
        }
        
        printf("%-20s", "Digit: ");
        for (int i = 0; i < 10; ++i) {
            printf("%d ", i);
        }
        printf("\n");
        printf("%-20s", "Occurrences: ");
        for (int i = 0; i < 10; ++i) {
            printf("%d ", digit_seen[i]);
        }
        printf("\n");
    }
    
    return 0;
}
