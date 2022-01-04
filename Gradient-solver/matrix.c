#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix * readFromFile(char * fname) {
		int r,c;
		int ir, ic;
		FILE * fin =  fopen(fname,"r");
		Matrix * mat = NULL;
		if (fin != NULL) {
			fscanf(fin,"%d %d",&r,&c);
			mat = createMatrix(r,c);
			if (mat != NULL) {
				for (ir = 0; ir < r; ir++) 
					for (ic = 0; ic < c; ic++)
						fscanf(fin, "%lf",&(mat->data[ir][ic]));
			} else {
						fprintf(stderr,"Wystąpił problem podczas tworzenia macierzy o rozmiarach %d x %d dla danych z pliku: %s\n", r, c, fname);
			}
            fclose(fin);
			} else {
				    fprintf(stderr,"Nie mogę otworzyć pliku o nazwie: %s\n", fname);
				}
		return mat;
}

void printToScreen(Matrix *mat) {
	int i,j;
	printf("[ \n");
	for (i = 0; i<mat->r; i++) {
		printf("  ");
		for (j = 0; j < mat->c; j++) {
			printf("%f ", mat->data[i][j]);
		}
		printf("; \n");
	}
	printf("]\n");
}

Matrix * createMatrix(int r, int c) {
		int i;
		Matrix * mat = (Matrix*) malloc(sizeof(Matrix));
		if (mat != NULL) {
			mat->r = r;
			mat->c = c;
			mat->data = (double**) malloc(sizeof(double*) * r);
			for (i=0; i < r; i++) {
					mat->data[i] = (double*) malloc(sizeof(double) * c);
			}
		}

		return mat;
}

void freeMatrix(Matrix * mat) {
  int i;
	for (i=0;i < mat->r; i++)
		free(mat->data[i]);
	free(mat->data);
	free(mat);
}

void multiplyMatrix(Matrix *ans,Matrix *mat1,Matrix *mat2)
{
    for (int i = 0; i < mat1->r; ++i) {
      for (int j = 0; j < mat2->c; ++j) {
          ans->data[i][j]=0;
         for (int k = 0; k < mat1->c; ++k) {
            ans->data[i][j] += mat1->data[i][k] * mat2->data[k][j];
         }
      }
   }
}

void addMatrix(Matrix *ans, Matrix *mat1, Matrix *mat2)
{
    for(int i=0;i<mat1->r;i++)
        for(int j=0;j<mat1->c;j++)
            ans->data[i][j]=mat1->data[i][j]+mat2->data[i][j];
}

void substractMatrix(Matrix *ans, Matrix *mat1, Matrix *mat2)
{
    for(int i=0;i<mat1->r;i++)
        for(int j=0;j<mat1->c;j++)
            ans->data[i][j]=mat1->data[i][j]-mat2->data[i][j];
}

double dot_product1(Matrix *mat)
{
    double sum=0;
    for(int i=0;i<mat->r;i++) sum+=mat->data[i][0]*mat->data[i][0];
    return sum;
}

double dot_product2(Matrix *mat1, Matrix *mat2)
{
    double sum=0;
    for(int i=0;i<mat1->r;i++) sum+=mat1->data[i][0]*mat2->data[i][0];
    return sum;
}

void multiplybynumMatrix(Matrix *ans,Matrix *mat1,double num)
{
    for(int i=0;i<ans->r;i++)
        for(int j=0;j<ans->c;j++)
            ans->data[i][j]=mat1->data[i][j]*num;
}

void copyMatrix(Matrix *ans,Matrix *mat)
{
    for(int i=0;i<mat->r;i++)
        for(int j=0;j<mat->c;j++) ans->data[i][j]=mat->data[i][j];
}