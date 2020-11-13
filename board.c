#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define LIN 3
#define COL 3

typedef struct _board {
    Matrix state;
    int turn; 
    int endGame;
} board;

Board createBoard(int op){
    int i, j;
    
    board *b = (board*)malloc(sizeof(board));
    b->state = newMatrix(LIN, COL);

    if(op == 1) b->turn = op;
    else b->turn = 0;

    b->endGame = 0;

    return b;
}

char rowCrossed(Matrix m){
    for(int i=0; i<COL; i++){
        if(m[i][0] == m[i][1] && m[i][1] == m[i][2] && m[i][0] != ' ')
            return m[i][0];
    }
    return ' ';
}

char columnCrossed(Matrix m){
    for(int i=0; i<COL; i++){
        if(m[0][i] == m[1][i] && m[1][i] == m[2][i] && m[0][i] != ' ')
            return m[0][i];
    }
    return ' ';
}

char diagonalCrossed(Matrix m){
    if(m[0][0] == m[1][1] && m[2][2] == m[1][1] && m[0][0] != ' ')
        return m[0][0];
    
    if(m[0][2] == m[1][1] && m[1][1] == m[2][0] && m[0][2] != ' ')
        return m[0][2];

    return ' ';
}

void checkWinner(Board brd){
    board *b = brd;
    Matrix m = getState(b);
    char r = ' ', c = ' ', d = ' ';

    r = rowCrossed(m);
    c = columnCrossed(m);
    d = diagonalCrossed(m);

    if(r != ' '){
        showInGame(b);
        if(r == 'o')
            printf("\nHUMANO VENCEU\n");
        else if(r == 'x')
            printf("\nMAQUINA VENCEU\n");
        setEndGame(b);
    }else if(c != ' '){ 
        showInGame(b);
        if(c == 'o')
            printf("\nHUMANO VENCEU\n");
        else if(c == 'x')
            printf("\nMAQUINA VENCEU\n");
        setEndGame(b);
    }else if(d != ' '){
        showInGame(b);
        if(d == 'o')
            printf("\nHUMANO VENCEU\n");
        else if(d == 'x')
            printf("\nMAQUINA VENCEU\n");
        setEndGame(b);
    }
}

Matrix getState(Board brd){
    board *b = brd;
    return b->state;
}

void setState(Board brd, int i, int j, char move){
    board *b = brd;
    Matrix m = getState(b);

    if(m[i][j] == ' '){
        m[i][j] = move;
        setTurn(b);
    }else{
        printf("ERR: Posição já ocupada, insira novamente em uma posição vazia.");
    }

    checkWinner(b);
}

int getTurn(Board brd){
    board *b = brd;
    return b->turn;
}

void setTurn(Board brd){
    board *b = brd;
    b->turn = !b->turn;
}

int getEndGame(Board brd){
    board *b = brd;
    return b->endGame;
}

void setEndGame(Board brd){
    board *b = brd;
    b->endGame = 1;
}

void freeBoard(Board brd){
    board *b = brd;
    freeMatrix(b->state);
    free(b);
}

void boardExample(){
    printf("\n> BOARD EXAMPLE\n");      
    printf("\n\t o|x|o\n\t-------\n\t x|o|x\n\t-------\n\t o|x|o\n\n");
}

void inputExample(){
    printf("\n> INPUT EXAMPLE\n");
    printf("\n\t 7|8|9\n\t-------\n\t 4|5|6\n\t-------\n\t 1|2|3\n\n");
}

void showInGame(Board brd){
    board *b = brd;
    printf("\n> BOARD\n");  
    printf("\n\t %c|%c|%c\n\t-------\n\t %c|%c|%c\n\t-------\n\t %c|%c|%c\n\n", 
    b->state[0][0], b->state[0][1], b->state[0][2], 
    b->state[1][0], b->state[1][1], b->state[1][2], 
    b->state[2][0], b->state[2][1], b->state[2][2]);
}
