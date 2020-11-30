#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define LIN 3
#define COL 3

void checkWinner(Board brd);
char rowCrossed(Matrix m);
char columnCrossed(Matrix m);
char diagonalCrossed(Matrix m);
void printWinner(Board brd, char w);
char setMove(int i, int j);
void clearState(Board brd, int i, int j);
void setStateAux(Board brd, int i, int j, char move);
int checkWinnerMinimax(Board brd, int depth);

typedef struct _board {
    Matrix state;
    int turn; 
    int endGame;
    int marked;
} board;

Board createBoard(int op){
    int i, j;
    
    board *b = (board*)malloc(sizeof(board));
    b->state = newMatrix(LIN, COL);

    if(op == 1) b->turn = op;
    else b->turn = 0;

    b->endGame = 0;

    b->marked = 0;

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

void printWinner(Board brd, char w){
    board * b = brd;
    showInGame(b);
    if(w == 'x')
        printf("\n ( →_→)     I WON, AS ALWAYS     ୧༼=◔益◔=୧ ༽ \n\n");
    else if(w == 'o')
        printf("\n ( →_→)     YOU WON, BUT I KNOW YOU CHEATED     ༼ง=ಠ益ಠ=༽ง \n\n");
    setEndGame(b);
}

void checkWinner(Board brd){
    board *b = brd;
    Matrix m = getState(b);
    char r = ' ', c = ' ', d = ' ';

    r = rowCrossed(m);
    c = columnCrossed(m);
    d = diagonalCrossed(m);

    if(r != ' ')
        printWinner(b, r);
    else if(c != ' ')
        printWinner(b, c);
    else if(d != ' ')
        printWinner(b, d);
    else if(getMarked(b) == 9){
        showInGame(b);
        printf("\n ( →_→)   YOU GOT LUCKY THIS TIME HUMAN, WE TIED   (ノಠ益ಠ) \n\n");
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
        b->marked += 1;
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

int getMarked(Board brd){
    board *b = brd;
    return b->marked;
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


// ################ IA IMPLEMENTATION ################

char findRandomMove(){
    int r = (rand() % 8) + 1;
    if(r == 1)  return '1';
    if(r == 2)  return '2';
    if(r == 3)  return '3';
    if(r == 4)  return '4';
    if(r == 5)  return '5';
    if(r == 6)  return '6';
    if(r == 7)  return '7';
    if(r == 8)  return '8';
    if(r == 9)  return '9';
}

char findBestMove(Board brd){
    board *b = brd;
    Matrix m = getState(b);
    int bestScore = -__INT_MAX__;
    int score;
    int x, y;
    char bestMove = ' ';

    for(int i=0; i<LIN; i++){
        for(int j=0; j<COL; j++){
            if(m[i][j] == ' '){
                setStateAux(b, i, j, 'x');
                score = minimax(b, getMarked(b), getTurn(b));
                clearState(b, i, j);
                if(score > bestScore){
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return  (x, y);
}

int minimax(Board brd, int depth, int isMaximazing){
    board *b = brd;
    Matrix m = getState(b);
    int result;
    int score;

    result = checkWinnerMinimax(b, depth);
    if(result != -73){
        score = result;
        return score;
    }

    if(isMaximazing){
        int bestScore = -__INT_MAX__;
        for(int i=0; i<LIN; i++){
            for(int j=0; j<COL; j++){
                if(m[i][j] == ' '){
                    setStateAux(b, i, j, 'x');
                    score = minimax(b, depth + 1, 0);
                    clearState(b, i, j);
                    if(score > bestScore)
                        bestScore = score;                    
                }
            }
        }
        return bestScore;
    }else{
        int bestScore = __INT_MAX__;
        for(int i=0; i<LIN; i++){
            for(int j=0; j<COL; j++){
                if(m[i][j] == ' '){
                    setStateAux(b, i, j, 'o');
                    score = minimax(b, depth + 1, 1);
                    clearState(b, i, j);
                    if(score < bestScore)
                        bestScore = score;                    
                }
            }
        }
        return bestScore;
    }
}


// ################ PRIVATE FUNCTIONS ################

int checkWinnerMinimax(Board brd, int depth){
    board *b = brd;
    Matrix m = getState(b);
    char r = ' ', c = ' ', d = ' ';

    r = rowCrossed(m);
    c = columnCrossed(m);
    d = diagonalCrossed(m);

    if(r != ' '){
        if(r == 'x') return 1 * (9 - depth);
        else return -1 * (9 - depth);
    }
    else if(c != ' '){
        if(c == 'x') return 1 * (9 - depth);
        else return -1 * (9 - depth);
    }
    else if(d != ' '){
        if(d == 'x') return 1 * (9 - depth);
        else return -1 * (9 - depth);
    }
    else if(getMarked(b) == 9)
        return 0;
    else 
        return -73;
}

char setMove(int i, int j){
    if(i == 2 && j == 0)    return '1';
    if(i == 2 && j == 1)    return '2';
    if(i == 2 && j == 2)    return '3';
    if(i == 1 && j == 0)    return '4';
    if(i == 1 && j == 1)    return '5';
    if(i == 1 && j == 2)    return '6';
    if(i == 0 && j == 0)    return '7';
    if(i == 0 && j == 1)    return '8';
    if(i == 0 && j == 2)    return '9';
}

void setStateAux(Board brd, int i, int j, char move){
    board *b = brd;
    Matrix m = getState(b);
    m[i][j] = move;
    b->marked += 1;
}

void clearState(Board brd, int i, int j){
    board *b = brd;
    Matrix m = getState(b);
    m[i][j] = ' ';
    b->marked -= 1;
}