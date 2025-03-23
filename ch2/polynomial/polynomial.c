#include <stdio.h>
#include <stdlib.h>
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
    if (x.coef[expon]!=0){
        printf("Attach Error: Exponent already exists\n");
        exit(1);
    }else{
        if (expon>x.degree){
            x.degree=expon;
        }
        x.coef[expon]=coef;
        return x;
    }
}

poly Remove(poly x,int expon){
    if (x.coef[expon]!=0){
        x.coef[expon]=0;
        return x;
    }else{
        printf("error remove");
        exit(1);
    }
}

poly SingleMult(poly x,float coef,int expon){
    for(int i=x.degree;i>=0;i--){
        if(x.coef[i]!=0){
            x.coef[i+expon]=x.coef[i]*coef;
        }
    }
    x.degree+=expon;
    return x;
}

poly Add(poly x,poly y){
    poly z=Zero();
    if (x.degree>=y.degree){
        z.degree=x.degree;
    }else{
        z.degree=y.degree;
    }
    for(int i=0;i<=z.degree;i++){
        z.coef[i]=x.coef[i]+y.coef[i];
    }
    return z;
}

poly Mult(poly x,poly y){
    poly z=Zero();
    for(int i=0;i<=x.degree;i++){
        for (int j=0;j<=y.degree;j++){
            z.coef[i+j]+=x.coef[i]*y.coef[j];
        }
    }
    z.degree=x.degree+y.degree;
    return z;
}

int main() {
    // 定義兩個多項式 A(x) = 3x^4 + 2x^2 + 1, B(x) = x^3 + 4
    poly A = Zero();
    A = Attach(A, 1, 2);
    A = Attach(A, 2, 1);
    A = Attach(A, 3, 0);

    poly B = Zero();
    B = Attach(B, 1.0, 1);
    B = Attach(B, 4.0, 0);

    // 測試加法
    poly C = Add(A, B);

    // 測試乘法
    poly D = Mult(A, B);

    // 印出結果
    printf("A(x) + B(x) = ");
    for (int i = C.degree; i >= 0; i--) {
        if (C.coef[i] != 0)
            printf("%.1fx^%d ", C.coef[i], i);
    }
    printf("\n");

    printf("A(x) * B(x) = ");
    for (int i = D.degree; i >= 0; i--) {
        if (D.coef[i] != 0)
            printf("%.1fx^%d ", D.coef[i], i);
    }
    printf("\n");

    return 0;
}
