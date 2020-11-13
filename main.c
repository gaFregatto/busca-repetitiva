#include <stdlib.h>
#include <stdio.h>
#include "board.h"

void menu(int *x);
void startGame(int *x);

int main(int argc, char *argv[]){
    int op = 0;
    menu(&op);
    startGame(&op);
    return 0;
}

void menu(int *x){
    boardExample();
    inputExample();
    printf("\n#### MENU ####\nPress to choose:\n1. Player First\n2. IA First\n> ");
    scanf("%d", &(*x));
}

void startGame(int *x){
    Board b = createBoard(*x);
    Matrix state = getState(b);
    int i, j;
    char move, posic;

    while(!getEndGame(b)){
        if(getTurn(b)) printf("\n(;´༎ຶД༎ຶ`) JOGUE HUMANO (つ◉益◉)つ\n");
        else printf("\n(つ´∀`)つ MINHA VEZ ლ(・ヮ・ლ)\n");

        inputExample();
        showInGame(b);
        printf("\nDigite o número da posição desejada: ");
        scanf("%c", &posic);

        if(getTurn(b)) move = 'o';
        else move = 'x';


        switch (posic){
        case '1':
            i = 2;
            j = 0;
            setState(b, i, j, move);
            break;

        case '2':
            i = 2;
            j = 1;
            setState(b, i, j, move);
            break;
        
        case '3':
            i = 2;
            j = 2;
            setState(b, i, j, move);
            break;
        
        case '4':
            i = 1;
            j = 0;
            setState(b, i, j, move);
            break;
        
        case '5':
            i = 1;
            j = 1;
            setState(b, i, j, move);
            break;
        
        case '6':
            i = 1;
            j = 2;
            setState(b, i, j, move);
            break;
        
        case '7':
            i = 0;
            j = 0;
            setState(b, i, j, move);
            break;

        case '8':
            i = 0;
            j = 1;
            setState(b, i, j, move);
            break;
        
        case '9':
            i = 0;
            j = 2;
            setState(b, i, j, move);
            break;
        case '0':
            printf("\nFechando programa..\n");
            setEndGame(b);
            break;
        default:
            printf("\nERR: Opção inválida. Digite um número de 0 a 9.\n");
        }
    }
    freeBoard(b);
}
