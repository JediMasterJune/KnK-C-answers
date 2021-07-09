#include <stdio.h>
#include <stdbool.h>

#define DEBUG

//typedef enum piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum chessPieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN } ChessPieces;
const int pieceValue[] = {[KING]=200, [QUEEN]=9, [ROOK]=5, [BISHOP]=3, [KNIGHT]=3, [PAWN]=1};