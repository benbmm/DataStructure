#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int row;
    int col;
    int val;
}mat;

#define max_terms 100

mat a[max_terms];
mat b[max_terms];
mat newB[max_terms];
mat d[max_terms];

int COMPARE(int a,int b){
    if (a>b){
        return 1;
    }else if(a==b){
        return 0;
    }else{
        return -1;
    }
}
void trans(mat a[],mat b[]){
    int row_term[a[0].col];
    int start[a[0].col];
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    for(int i=0;i<a[0].col;i++){
        row_term[i]=0;
    }
    for (int i=1;i<=a[0].val;i++){
        row_term[a[i].col]++;
    }
    start[0]=1;
    for (int i=1;i<a[0].col;i++){
        start[i]=start[i-1]+row_term[i-1];
    }
    for (int i=1;i<=a[0].val;i++){
        b[start[a[i].col]].row=a[i].col;
        b[start[a[i].col]].col=a[i].row;
        b[start[a[i].col]].val=a[i].val;
        start[a[i].col]++;
    }
}
void print_matrix(const mat m[]) {
    printf("row\tcol\tval\n");
    for (int i = 0; i <= m[0].val; i++) {
        printf("%d\t%d\t%d\n", m[i].row, m[i].col, m[i].val);
    }
}
void storesum(mat d[],int *totalD,int row,int column,int *sum){
    if(*sum){
        if(*totalD<max_terms){
            (*totalD)++;
            d[*totalD].row = row;
            d[*totalD].col = column;
            d[*totalD].val = *sum;
            *sum = 0;   
        }else{
            fprintf(stderr, "Number of terms in product exceeds %d\n", max_terms);
            exit(1);
        }
    }
}

void mult(mat a[],mat b[]){
    int rowsA=a[0].row;
    int colsA=a[0].col;
    int rowsB=b[0].row;
    int colsB=b[0].col;
    int totalA=a[0].val;
    int totalB=b[0].val;
    int row=a[1].row;
    int column;
    int sum=0;
    int totalD=0;
    int rowBegin=1;
    trans(b,newB);
    a[totalA + 1].row = rowsA;
    a[totalA + 1].col=0;
    a[totalA + 1].val=0;
    newB[totalB + 1].row = colsB;
    newB[totalB + 1].col = 0;
    newB[totalB + 1].val = 0;

    for(int i=1;i<=totalA;){
        column=newB[1].row;
        for(int j=1;j<=totalB+1;){
            if (a[i].row!=row){
                storesum(d,&totalD,row,column,&sum);
                i=rowBegin;
                for(;newB[j].row==column;j++);
                column=newB[j].row;
            }else if(newB[j].row!=column){
                storesum(d,&totalD,row,column,&sum);
                i=rowBegin;
                column=newB[j].row;
            }else{
                switch(COMPARE(a[i].col,newB[j].col)){
                    case 0:
                        sum+=a[i].val*newB[j].val;
                        break;
                    case 1:
                        j++;
                        break;
                    case -1:
                        i++;
                }
            }
        }
        
        for (;a[i].row==row;i++);
        rowBegin=i;
        row=a[i].row;
    }
    
    storesum(d, &totalD, row, column, &sum);
    d[0].row = rowsA;
    d[0].col = colsB;
    d[0].val = totalD;
}

int main() {
    // 定義矩陣 A (2x3)
    // A =
    // [15 0 0]
    // [0 22 0]
    a[0].row = 2;
    a[0].col = 3;
    a[0].val = 2;
    a[1] = (mat){0, 0, 15};
    a[2] = (mat){1, 1, 22};

    // 定義矩陣 B (3x2)
    // B =
    // [1 0]
    // [0 1]
    // [0 0]
    b[0].row = 3;
    b[0].col = 2;
    b[0].val = 2;
    b[1] = (mat){0, 0, 1};
    b[2] = (mat){1, 1, 1};

    // 執行乘法運算
    mult(a, b);

    // 輸出結果矩陣 D
    printf("=== 矩陣 A ===\n");
    print_matrix(a);
    printf("\n=== 矩陣 B ===\n");
    print_matrix(b);
    printf("\n=== 乘積矩陣 D = A * B ===\n");
    print_matrix(d);

    return 0;
}
