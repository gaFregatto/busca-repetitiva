#ifndef board_h
#define board_h

#include "matrix.h"

typedef void *Board;

Board createBoard(int op);
Matrix getState(Board brd);
void setState(Board brd, int i, int j, char move);
int getTurn(Board brd);
int getMarked(Board brd);
void setTurn(Board brd);
int getEndGame(Board brd);
void setEndGame(Board brd);
void freeBoard(Board brd);
void boardExample();
void inputExample();
void showInGame(Board brd);

#endif 