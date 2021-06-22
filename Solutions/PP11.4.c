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
 * rank(숫자) : 2,3,4,5,6,7,8,9,ten,jack,queen,king,ace
 * suit(문양) : clubs, diamonds, hearts, spades
 * royal flush (same suit + ten,jack,queen,king,ace)
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

#define RANK 0
#define SUIT 1

/* external variables */

/* prototypes */
void read_cards(int hand[NUM_CARDS][2]);
void
analyze_hand(int hand[NUM_CARDS][2], bool* pRoyal, bool* pStraight, bool* pFlush, bool* pFour, bool* pThree,
             int* pPairs);
//void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    bool royal, straight, flush, four, three;
    int pairs;   /* can be 0, 1, or 2 */
    //int num_in_rank[NUM_RANKS] = {0};
    //int num_in_suit[NUM_SUITS] = {0};
    int hand[NUM_CARDS][2] = {0}; // row: n번째 카드(0~4), column: 각각 rank와 suit 저장
    for (;;) {
        read_cards(hand);
        analyze_hand(hand, &royal, &straight, &flush, &four, &three, &pairs);
        if (royal && flush) printf("Royal flush");
        else if (straight && flush) printf("Straight flush");
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
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(int hand[NUM_CARDS][2])
{
    //bool card_exists[NUM_RANKS][NUM_SUITS] = {false}; // 중복 체크용
    char ch, rank_ch, suit_ch; //ch는 extra characters 제거용
    int rank, suit;
    bool bad_card;
    int cards_read = 0;
    
    for (int i = 0; i < NUM_CARDS; i++) {
        for (int j = 0; j < 2; ++j) {
            hand[i][j] = 0;
        }
    }
    
    /*
    for (suit = 0; suit < NUM_SUITS; suit++)
        num_in_suit[suit] = 0;
     */
    //초기화
    
    while (cards_read < NUM_CARDS) {
        bad_card = false;
        
        printf("Enter a card: ");
        
        rank_ch = (char) getchar();
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
        
        suit_ch = (char) getchar();
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
        
        while ((ch = (char) getchar()) != '\n') {
            if (ch != ' ') bad_card = true;
        }
        for (int i = 0; i < cards_read; ++i) {
            if (hand[i][0] == rank && hand[i][1] == suit) {
                printf("Duplicate card;\n");
                bad_card = true;
                break;
            }
        }
        if (bad_card)
            printf("Bad card; ignored.\n");
        else {
            hand[cards_read][RANK] = rank;
            hand[cards_read][SUIT] = suit;
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
void
analyze_hand(int hand[NUM_CARDS][2], bool* pRoyal, bool* pStraight, bool* pFlush, bool* pFour, bool* pThree,
             int* pPairs)
{
    int num_consec = 1;
    int rank; //suit;
    int rankCount = 0;
    int max;
    
    *pRoyal = false;
    *pStraight = false;
    //*pFlush = false;
    *pFour = false;
    *pThree = false;
    *pPairs = 0;
    
    /* check for flush */
    *pFlush = true;
    for (int i = 1; i < NUM_CARDS; ++i) {
        if (hand[i - 1][SUIT] != hand[i][SUIT]) {
            *pFlush = false;
            break;
        }
    }
    
    /* check for straight */
    //rank = 0;
    //while (hand[0][rank] == 0) rank++; //최초의 랭크가 나타날 때까지 스킵
    //for (int i = hand[0][0]; i < NUM_RANKS &&; ++i) {
    
    max = hand[0][RANK];
    for (int i = 1; i < NUM_CARDS; ++i) {
        if (max < hand[i][RANK])
            max = hand[i][RANK];
    }
    for (int j = 0; j < NUM_CARDS; ++j) { //검사를 5번 반복
        for (int i = 0; i < NUM_CARDS; ++i) {
            if (hand[i][RANK] == max - 1) {
                max--;
                num_consec++;
                break;
            }
        }
    }
    
    /* ace-low Straight 구현 */
    if (num_consec < NUM_CARDS && max == 14 - 2) {
        num_consec = 1; //연속수 초기화
        max = 5 - 2; //max를 five로 설정한다. (ace의 존재는 이미 확인됨)
        for (int j = 0; j < NUM_CARDS; ++j) { //검사를 5번 반복
            for (int i = 0; i < NUM_CARDS; ++i) {
                if (hand[i][RANK] == max) { //five부터 시작하여 4,3,2의 존재를 확인한다.
                    max--;
                    num_consec++;
                    break;
                }
            }
        }
    }
    
    if (num_consec == NUM_CARDS) {
        if (max == 10 - 2) {
            *pRoyal = true;
        }// 14 -> 10
        *pStraight = true;
        return;
    }
    
    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (rank = 0; rank < NUM_RANKS; rank++) {
        rankCount = 0;
        for (int i = 0; i < NUM_CARDS; ++i) {
            if (hand[i][0] == rank) rankCount++;
        }
        if (rankCount == 4) *pFour = true;
        else if (rankCount == 3) *pThree = true;
        else if (rankCount == 2) *pPairs++;
    }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
/*
void print_result(void)
{
   if (royal && flush) printf("Royal flush");
   else if (straight && flush) printf("Straight flush");
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

 */