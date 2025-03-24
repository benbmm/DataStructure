#include <stdio.h>

typedef struct{
    int row;
    int col;
    int val;
}mat;

#define max_terms 100

mat a[max_terms];
mat b[max_terms];

void mult(mat a[],mat b[]){
    int rowsA=a[0].row;
    int colsA=a[0].col;
    int rowsB=b[0].row;
    int colsB=b[0].col;
    int totalA=a[0].val;
    int totalB=b[0].val;
    int row=a[1].row;
    for(int i=1;i<=totalA)
}