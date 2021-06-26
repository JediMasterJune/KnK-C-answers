/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. LENGTH. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* reverse.c (Chapter 8, page 164) */
/* Reverses a series of numbers */

#include <stdio.h>

#define LENGTH (sizeof(a)/sizeof(a[0]))

int main(void)
{
    int a[10], i;
    
    printf("Enter %d numbers: ", LENGTH);
    for (i = 0; i < LENGTH; i++)
        scanf("%d", &a[i]);
    
    printf("In reverse order:");
    for (i = LENGTH - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");
    
    return 0;
}
