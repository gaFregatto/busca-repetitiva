#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define LIN 3
#define COL 3

typedef struct _board {
    Matrix state;
    int turn; 
} board;

void boardExample(){
    printf("\n> BOARD EXAMPLE\n");      
    printf("\n\t o|x|o\n\t-------\n\t x|o|x\n\t-------\n\t o|x|o\n\n");
}

void inputExample(){
    printf("\n> INPUT EXAMPLE\n");
    printf("\n\t 7|8|9\n\t-------\n\t 4|5|6\n\t-------\n\t 1|2|3\n\n");
}

Board createBoard(int op){
    int i, j;
    
    board *b = (board*)malloc(sizeof(board));
    b->state = newMatrix(LIN, COL);

    if(op == 1) b->turn = op;
    else b->turn = 0;

    return b;
}

Matrix getState(Board brd){
    board *b = brd;
    return b->state;
}

int getTurn(Board brd){
    board *b = brd;
    return b->turn;
}

void freeBoard(Board brd){
    board *b = brd;
    freeMatrix(b->state);
    free(b);
}

void showInGame(Board brd){
    board *b = brd;

    printf("\n\t %c|%c|%c\n\t-------\n\t %c|%c|%c\n\t-------\n\t %c|%c|%c\n\n", 
    b->state[0][0], b->state[0][1], b->state[0][2], 
    b->state[1][0], b->state[1][1], b->state[1][2], 
    b->state[2][0], b->state[2][1], b->state[2][2]);
}