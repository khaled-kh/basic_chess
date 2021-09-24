#ifndef CHESS_H
#define CHESS_H
#include "chess_moveset.h"

typedef struct _ChessGame
{
    float eval;
    int board[8][8];
    int m[8][8], t[8][8];
    int captureW[20];
    int captureB[20];
    int count, check;
    int castleWS, castleWL;
    int castleBS, castleBL;
    char from[32], to[32];
    Point fromP, toP;
}
ChessGame;

void init_chess_board(int board[8][8])
{
    for(int i=0; i<8; i++)
    for(int j=0; j<8; j++)
    board[i][j] = EMPTY;
    
    board[0][0] =     board[0][7] =      ROOK;
    board[0][1] =     board[0][6] =    KNIGHT;
    board[0][2] =     board[0][5] =    BISHOP;
    board[0][3] = QUEEN;   board[0][4] = KING;
    for(int i=0; i<8; i++) board[1][i] = PAWN;

    board[7][0] =     board[7][7] =     -ROOK;
    board[7][1] =     board[7][6] =   -KNIGHT;
    board[7][2] =     board[7][5] =   -BISHOP;
    board[7][3] = -QUEEN; board[7][4] = -KING;
    for(int i=0; i<8; i++) board[6][i] =-PAWN;
}

void print_chess_board_white(int board[8][8])
{
    for(int i=7; i>=0; i--)
    {
        printf("\n %d | ",i+1);
        for(int j=0; j<8; j++) printf("%3d ",board[i][j]);
    }
    printf("\n---+");for(int j=0; j<8; j++)printf("----");
    printf("\n   |");for(int j=0; j<8; j++)printf("   %c",'a'+j);
}

void print_chess_board_black(int board[8][8])
{
    for(int i=0; i<8; i++)
    {
        printf("\n %d | ",i+1);
        for(int j=0; j<8; j++) printf("%3d ",board[i][j]);
    }
    printf("\n---+");for(int j=0; j<8; j++)printf("----");
    printf("\n   |");for(int j=0; j<8; j++)printf("   %c",'a'+j);
}

void print_chess_board(int board[8][8], int white)
{
    white
    ?   print_chess_board_white(board)
    :   print_chess_board_black(board);
}

float basic_eval(int board[8][8])
{
    return 
        (board[0][0]+board[0][1]+board[0][2]+board[0][3]
        +board[0][4]+board[0][5]+board[0][6]+board[0][7]
        +board[1][0]+board[1][1]+board[1][2]+board[1][3]
        +board[1][4]+board[1][5]+board[1][6]+board[1][7]
        +board[2][0]+board[2][1]+board[2][2]+board[2][3]
        +board[2][4]+board[2][5]+board[2][6]+board[2][7]
        +board[3][0]+board[3][1]+board[3][2]+board[3][3]
        +board[3][4]+board[3][5]+board[3][6]+board[3][7]
        +board[4][0]+board[4][1]+board[4][2]+board[4][3]
        +board[4][4]+board[4][5]+board[4][6]+board[4][7]
        +board[5][0]+board[5][1]+board[5][2]+board[5][3]
        +board[5][4]+board[5][5]+board[5][6]+board[5][7]
        +board[6][0]+board[6][1]+board[6][2]+board[6][3]
        +board[6][4]+board[6][5]+board[6][6]+board[6][7]
        +board[7][0]+board[7][1]+board[7][2]+board[7][3]
        +board[7][4]+board[7][5]+board[7][6]+board[7][7]) / 2.0f ;
}

void init_chess_game(ChessGame *g)
{
    g->count    = 1;
    g->castleBL = 1;
    g->castleBS = 1;
    g->castleWL = 1;
    g->castleWS = 1;
    g->from[0] = g->to[0] = '\0';
    init_chess_board(g->board);
    g->eval = basic_eval(g->board);
}

int selfcheck(ChessGame *g)
{
    for(int i=0;i<64;i++)g->t[i/8][i%8]=g->board[i/8][i%8];
    g->t[g->to[1]-'1'][g->to[1]-'a']=g->board[g->from[1]-'1'][g->from[1]-'a'];
    g->board[g->from[1]-'1'][g->from[1]-'a']=EMPTY;
    int c = is_check(g->t);
    return abs(c) == CHECK_WHITE
        || abs(c) == CHECKMATE_WHITE;
}

#endif