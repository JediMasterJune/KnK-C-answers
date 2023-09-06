/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

typedef struct word
{
  int len;
  struct word *next;
  char wordString[];
} Word;

Word *line = NULL;

// char line[MAX_LINE_LEN+1];

int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  Word *prev = line;
  while (line)
  {
    prev = line;
    line = line->next;
    free(prev);
  }
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  int wordLen = strlen(word);
  Word *newWord = malloc(sizeof(Word) + wordLen + 1);
  // strlen은 null문자 제외한 문자열 길이를 리턴한다.

  if (!newWord)
  {
    printf("malloc failed");
    exit(EXIT_FAILURE);
  }
  strcpy(newWord->wordString, word);
  newWord->len = wordLen;
  newWord->next = NULL;

  // if (num_words > 0) {
  //   // line[line_len] = ' ';
  //   // line[line_len+1] = '\0';
  //   // line_len++;
  // }

  if (num_words > 0)
  {
    line_len++; // 이전 단어와 현재 단어 사이에 공백 추가
  }

  Word *cur = line;
  if (line) {
    for (; cur->next; cur = cur->next)
      ;
    cur->next = newWord;
  }
  else {
    line = newWord;
  }

  num_words++;
  line_len += wordLen;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  // printf("write_line Called");
  int extra_spaces, spaces_to_insert, i;
  extra_spaces = MAX_LINE_LEN - line_len;

  Word *cur = line;

  while (cur)
  {
    printf(cur->wordString);

    if (num_words > 1) // Devide by zero 매우 주의
    {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (i = 1; i <= spaces_to_insert + 1; i++)
        putchar(' ');
      extra_spaces -= spaces_to_insert;
    }

    cur = cur->next;
    num_words--;
  }
  putchar('\n');
}

void flush_line(void)
{
  // printf("flush_line Called");
  Word *cur = line;
  if (cur)
  {
    if (line_len > 0)
    {
      for (int i = 0; i < num_words; i++)
      {
        printf(cur->wordString);
        cur = cur->next;
        if (cur) {
          putchar (' ');
        }
      }
    }
  }
}
