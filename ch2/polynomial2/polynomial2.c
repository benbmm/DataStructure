#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int exp;
    float coef;
}poly;

poly terms[MAX_TERMS];
int avail=0;

void Attach(poly x,float cofe,int exp);
void padd(int startx,int finisfx,int starty,int finishy,int *startd,int *finishd);
int COMPARE(poly x,poly y);

void Attach(poly x,float cofe,int exp){
    if (avail>=MAX_TERMS){
        
    }
}