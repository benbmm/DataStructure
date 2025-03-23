#include <stdio.h>
#define MAX_DEGREE 100
typedef struct {
    int degree;
    float coef[MAX_DEGREE];
}poly;

poly Zero(){
    poly poly;
    poly.degree=0;
    for(int i=0;i<MAX_DEGREE;i++){
        poly.coef[i]=0;
    }
    return poly;
}

int IsZero(poly x){
    if(x.degree==0 && x.coef[x.degree]==0){
        return 1;
    }else{
        return 0;
    }
}

float Coef(poly x,int expon){
    if (expon>x.degree || expon<0){
        return 0;
    }else{
        return x.coef[expon];
    }
}

int Lead_Exp(poly x){
    return x.degree; 
}

poly Attach(poly x,float coef,int expon){
    
}