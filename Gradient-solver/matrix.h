#ifndef _MAT_IO_H
#define _MAT_IO_H
#include <stdio.h>

typedef struct _Matrix {
		int r,c;
		double **data;
} Matrix;

Matrix * readFromFile(FILE *in);

void printToScreen(Matrix *mat);

Matrix * createMatrix(int r, int c);

void freeMatrix(Matrix *mat);

void multiplyMatrix(Matrix *ans,Matrix *mat1,Matrix *mat2);

void addMatrix(Matrix *ans, Matrix *mat1, Matrix *mat2);

void substractMatrix(Matrix *ans, Matrix *mat1, Matrix *mat2);

double dot_product1(Matrix *mat);

double dot_product2(Matrix *mat1, Matrix *mat2);

void multiplybynumMatrix(Matrix *ans,Matrix *mat1,double num);

void copyMatrix(Matrix *ans,Matrix *mat);

void putentryMatrix(Matrix* mat, int i, int j, double num);

void addtoentryMatrix(Matrix *mat, int i, int j, double num);

double getentryMatrix(Matrix* mat, int i, int j );

#endif
