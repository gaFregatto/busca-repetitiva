#include <stdlib.h>
#include <stdio.h>
#include "board.h"

void menu(int *x){
    boardExample();
    inputExample();
    printf("\n#### MENU ####\nPress to choose:\n1. Player First\n2. IA First\n> ");
    scanf("%d", &(*x));
}

int main(int argc, char *argv[]){
    int op = 0;
    menu(&op);
    Board b = createBoard(op);
    showInGame(b);
    freeBoard(b);
    return 0;
}