/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN + 2]; //One for '*' and one for '\0'
    int word_len; //stores the length of current word
    
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1); //One for '*'
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line(); //The last line
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) { //One for '\0'
            write_line();
            clear_line();
        }
        add_word(word);
    }
}
