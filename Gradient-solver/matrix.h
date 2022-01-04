#ifndef _MAT_IO_H
#define _MAT_IO_H

typedef struct _Matrix {
		int r,c;
		double **data;
} Matrix;

Matrix * readFromFile(char * fname);

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

#endif