#ifndef CHESS_DEFINITIONS_H
#define CHESS_DEFINITIONS_H
#include <stdio.h>
#include <stdlib.h>

#define BIT(var,pos) ((var) & (1ULL<<(pos)))

#define EMPTY   0
#define PAWN    2
#define KNIGHT  6
#define BISHOP  7
#define ROOK    10
#define QUEEN   18
#define KING    1

#define NO_CHECK             0
#define CHECK_WHITE          1
#define CHECK_BLACK         -1
#define CHECKMATE_WHITE      2
#define CHECKMATE_BLACK     -2
#define STALEMATE_WHITE      3
#define STALEMATE_BLACK     -3

typedef struct _Point { int x; int y; } Point;

int isFilex(char x) { return x >= 'a' && x <= 'h'; }
int isRankx(char x) { return x >= '1' && x <= '8'; }
int getFilex(char x) { return x-'a'; }
int getRankx(char x) { return x-'1'; }

#endif