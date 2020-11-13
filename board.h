#ifndef board_h
#define board_h

#include "matrix.h"

typedef void *Board;

void boardExample();
void inputExample();
Board createBoard(int op);
Matrix getState(Board brd);
int getTurn(Board brd);
void freeBoard(Board brd);
void showInGame(Board brd);

#endif 