#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix newMatrix(int i, int j){
    int k, x, y;
    Matrix m = malloc(i * sizeof(char*));
    m[0] = malloc(i * j * sizeof(char));

    for(k=1; k<i; k++){
        m[k] = m[0] + k * j;
    }

    for(x=0; x<i; x++){
        for(y=0; y<j; y++){
            m[x][y] = ' ';
        }
    }
    return m;
}

void freeMatrix(Matrix mtx){
    Matrix m = mtx;
    free(m[0]);
    free(m);
}