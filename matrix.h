#ifndef matrix_h
#define matrix_h

typedef char** Matrix;

Matrix newMatrix(int i, int j);
void freeMatrix(Matrix mtx);

#endif