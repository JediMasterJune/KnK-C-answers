/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. RANGE. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* reverse.c (Chapter 8, page 164) */
/* Reverses a series of numbers */

#include <stdio.h>

#define RANGE (sizeof(a)/sizeof(a[0]))

int main(void)
{
    int a[10], i;
    
    printf("Enter %d numbers: ", RANGE);
    for (i = 0; i < RANGE; i++)
        scanf("%d", &a[i]);
    
    printf("In reverse order:");
    for (i = RANGE - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");
    
    return 0;
}
