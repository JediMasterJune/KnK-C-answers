/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* remind.c (Chapter 13, page 294) */
/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);
void bufClear(void);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char monthStr[7 + 7], day_str[4], timeStr[7], msg_str[MSG_LEN + 1];
    int month, day, i, j, num_remind = 0;
    int hour, minute, time;
    
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        
        printf("Enter month/day, time and reminder: ");
        
        scanf("%2d", &month);
        
        if (month == 0)
            break;
        else if (month < 0 || month > 12) {
            printf("There is no such month\n");
            bufClear();
            continue;
        }
        sprintf(monthStr, "%2d", month);
        
        scanf(" /%2d", &day);
        if (day < 0 || day > 31) {
            printf("There is no such day\n");
            bufClear();
            continue;
        }
        sprintf(day_str, "/%2d", day);
        
        scanf("%2d :%2d", &hour, &minute);
        time = hour * 60 + minute;
        
        if (time < 0 || time > 24 * 60 || minute > 59 || minute < 0) { //hour는 time에 의해 자동으로 통제됨. 분은 따로
            printf("Invalid time!\n");
            bufClear();
            continue;
        }
        sprintf(timeStr, " %.2d:%.2d", hour, minute);
        
        read_line(msg_str, MSG_LEN);
        
        strcat(monthStr, day_str);
        strcat(monthStr, timeStr); //미리 날짜스트링에 넣어서 비교가 용이하게 하기
        
        for (i = 0; i < num_remind; i++)
            if (strcmp(monthStr, reminders[i]) <
                0) // 이미 있는 리마인더들과 비교해서 day_str에 담긴 날짜 또는 시간, 또는 알파벳순까지 따져서 더 작아지는 순간 멈춤
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]); // 그 자리부터 아래에있는 리마인더 하나씩 밀어버린다.
        
        strcpy(reminders[i], monthStr);
        strcat(reminders[i], msg_str);
        
        num_remind++;
    }
    
    printf("\n%6s%6s Reminder\n", "Date", "Time");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}


void bufClear(void)
{
    while (getchar() != '\n');
}
