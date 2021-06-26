/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* poker.c (Chapter 10, page 233) */
/* Classifies a poker hand */

/* 포커 규칙
 * suit(문양) : clubs, diamonds, hearts, spades
 * rank(숫자) : two(0),three(1), four(2), five(3), six(4), seven(5), eight(6), nine(7), ten(8), jack(9), queen(a), king(b), ace(c)
 * straight flush (straight + flush)
 * four-of-a-kind (four cards of the same rank)
 * full house (a three-of-a-kind and a pair)
 * flush (five cards of the same suit)
 * straight (five cards with consecutive ranks)
 * three-of-a-kind (three cards of the same rank)
 * two pairs
 * pair (two cards of the same rank)
 * high card (any other card)
*/

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13 //0~c
#define NUM_SUITS 4 //clubs,diamonds,hearts,spades
#define NUM_CARDS 5 //hand

/* external variables */
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

/* prototypes */
void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(int num_in_rank[], int num_in_suit[]);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    int num_in_rank[NUM_RANKS] = {0};
    int num_in_suit[NUM_SUITS] = {0};
    for (;;) {
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit);
        print_result();
    }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(int num_in_rank[], int num_in_suit[])
{
    bool card_exists[NUM_RANKS][NUM_SUITS] = {false}; // 중복 체크용
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;
    
    for (rank = 0; rank < NUM_RANKS; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < NUM_SUITS; suit++)
            card_exists[rank][suit] = false;
    }
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;
    //초기화
    
    while (cards_read < NUM_CARDS) {
        bad_card = false;
        
        printf("Enter a card: ");
        
        rank_ch = getchar();
        switch (rank_ch) {
            case '0':
                exit(EXIT_SUCCESS);
            case '2':
                rank = 0;
                break;
            case '3':
                rank = 1;
                break;
            case '4':
                rank = 2;
                break;
            case '5':
                rank = 3;
                break;
            case '6':
                rank = 4;
                break;
            case '7':
                rank = 5;
                break;
            case '8':
                rank = 6;
                break;
            case '9':
                rank = 7;
                break;
            case 't':
            case 'T':
                rank = 8;
                break;
            case 'j':
            case 'J':
                rank = 9;
                break;
            case 'q':
            case 'Q':
                rank = 10;
                break;
            case 'k':
            case 'K':
                rank = 11;
                break;
            case 'a':
            case 'A':
                rank = 12;
                break;
            default:
                bad_card = true;
        }
        
        suit_ch = getchar();
        switch (suit_ch) {
            case 'c':
            case 'C':
                suit = 0;
                break;
            case 'd':
            case 'D':
                suit = 1;
                break;
            case 'h':
            case 'H':
                suit = 2;
                break;
            case 's':
            case 'S':
                suit = 3;
                break;
            default:
                bad_card = true;
        }
        
        //입력간 값을 바탕으로 rank와 suit 값 결정
        
        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;
        
        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card; ignored.\n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(int num_in_rank[], int num_in_suit[])
{
    int num_consec = 0;
    int rank, suit;
    
    straight = false;
    flush = false;
    four = false;
    three = false;
    pairs = 0;
    
    /* check for flush */
    for (suit = 0; suit < NUM_SUITS; suit++)
        if (num_in_suit[suit] == NUM_CARDS)
            flush = true;
    
    /* check for straight */
    rank = 0;
    while (num_in_rank[rank] == 0) rank++; //최초의 랭크가 나타날 때까지 스킵
    for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
        num_consec++;
    if (num_consec == NUM_CARDS) {
        straight = true;
        return;
    }
    
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        if (num_in_rank[rank] == 4) four = true;
        if (num_in_rank[rank] == 3) three = true;
        if (num_in_rank[rank] == 2) pairs++;
    }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four) printf("Four of a kind");
    else if (three &&
             pairs == 1)
        printf("Full house");
    else if (flush) printf("Flush");
    else if (straight) printf("Straight");
    else if (three) printf("Three of a kind");
    else if (pairs == 2) printf("Two pairs");
    else if (pairs == 1) printf("Pair");
    else printf("High card");
    
    printf("\n\n");
}
