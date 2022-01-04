#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gradient.h"

int main(int argc, char **argv)
{
    Matrix *a=readFromFile("a");
    Matrix *b=readFromFile("b");
    Matrix *ans=gradient_solver(a,b);
    printToScreen(ans);
    freeMatrix(ans);
}