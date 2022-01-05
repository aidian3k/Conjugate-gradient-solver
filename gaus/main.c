#include "gauss.h"
#include "backsubst.h"
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

int test (char *Ax, char *bx, char *wx);
int matrixCompare(Matrix *x, Matrix *w );

int
main (int argc, char **argv)
{
  int res;
  FILE *in=fopen(argv[1],"r");
  FILE *in2=fopen(argv[2],"r");
  Matrix *A = readFromFile (in);
  Matrix *b = readFromFile (in2);
  Matrix *x;

  if (A == NULL)
    return -1;
  if (b == NULL)
    return -2;
  printf ("Wczytane dane macierzy:\n");
  printToScreen (A);
  printf ("\nWektor b:\n");
  printToScreen (b);
  res = eliminate (A, b);
  x = createMatrix (b->r, 1);
  if (x != NULL)
    {
      res = backsubst (x, A, b);
      if(res==1) {
	fprintf(stderr, "%s:Wprowadzono macierz osobliwa( czyli taka, dla ktorej rzad jest mniejszy od rozmiaru wektora x)", argv[0]);
	return EXIT_FAILURE;
      }
      if(res==2) {
	fprintf(stderr, "Błąd! Wprowadzono nieprawidłowe rozmiary macierzy");
	return EXIT_FAILURE;
      }
      printf ("\nMacierz wynikow:\n");
      printToScreen (x);
      freeMatrix (x);
    }
  else
    {
      fprintf (stderr,
	       "Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
    }
  freeMatrix (A);
  freeMatrix (b);
 } 


