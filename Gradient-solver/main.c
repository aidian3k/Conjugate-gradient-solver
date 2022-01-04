#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gradient.h"

int main(int argc, char **argv)
{
    FILE *in1=argc>1 ? fopen(argv[1],"r") : stdin;
    FILE *in2=argc>2 ? fopen(argv[2],"r") : stdin;
    Matrix *a=readFromFile(in1);
    Matrix *b=readFromFile(in2);
    Matrix *ans=gradient_solver(a,b);
    printToScreen(ans);
    freeMatrix(ans);
}
