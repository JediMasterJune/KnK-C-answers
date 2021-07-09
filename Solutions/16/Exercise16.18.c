#include <stdio.h>
#include <stdbool.h>

#define DEBUG

typedef enum piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum color { BLACK, WHITE } Color;

typedef struct square {
    Piece kind;
    Color color;
} Square;

Square board[8][8] = {
        [6] = {{PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK}, {PAWN, BLACK},
               {PAWN, BLACK}}, //Black
        [1] = {{PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE},
               {PAWN, WHITE}}, //White
        [7] = {[0]={ROOK, BLACK}, [7]={ROOK, BLACK}, [1]={KNIGHT, BLACK}, [6]={KNIGHT, BLACK}, [2]={BISHOP,
                                                                                                    BLACK}, [5]={BISHOP,
                                                                                                                 BLACK}, [3]={
                QUEEN, BLACK}, [4]={KING, BLACK}}, //Black
        [0] = {[0]={ROOK, WHITE}, [7]={ROOK, WHITE}, [1]={KNIGHT, WHITE}, [6]={KNIGHT, WHITE}, [2]={BISHOP,
                                                                                                    WHITE}, [5]={BISHOP,
                                                                                                                 WHITE}, [3]={
                QUEEN, WHITE}, [4]={KING, WHITE}} //White
};