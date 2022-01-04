#include "matrix.h"
#include <stdio.h>
#include <math.h>

Matrix *gradient_solver(Matrix *a,Matrix *b)
{
    Matrix *r=createMatrix(b->r,b->c);
    Matrix *r_prev=createMatrix(b->r,b->c);
    Matrix *x_prev=createMatrix(b->r,b->c);
    Matrix *x=createMatrix(b->r,b->c);
    Matrix *holder=createMatrix(b->r,b->c);
    Matrix *p=createMatrix(b->r,b->c);
    Matrix *p_prev=createMatrix(b->r,b->c);
    copyMatrix(x_prev,b);
    multiplyMatrix(holder,a,x_prev);
    substractMatrix(r_prev,b,holder);
    copyMatrix(p_prev,r_prev);
    double rsold=dot_product1(r_prev);
    while(1)
    {
        multiplyMatrix(holder,a,p_prev);
        double alpha=rsold/dot_product2(p_prev,holder);
        multiplybynumMatrix(holder,p_prev,alpha);
        addMatrix(x,x_prev,holder);
        multiplyMatrix(holder,a,p_prev);
        multiplybynumMatrix(holder,holder,alpha);
        substractMatrix(r,r_prev,holder);
        double rsnew=dot_product1(r);
        if(sqrt(rsnew)<0.0000000001) break;
        multiplybynumMatrix(holder,p_prev,rsnew/rsold);
        addMatrix(p,r,holder);
        rsold=rsnew;
        copyMatrix(x_prev,x);
        copyMatrix(r_prev,r);
        copyMatrix(p_prev,p);
    }
    freeMatrix(r);
    freeMatrix(r_prev);
    freeMatrix(x_prev);
    freeMatrix(holder);
    freeMatrix(p);
    freeMatrix(p_prev);
    return x;
}