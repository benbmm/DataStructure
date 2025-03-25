#include <stdio.h>

typedef struct{
    int row;
    int col;
    int val;
}mat;

#define max_terms 100

mat a[max_terms];
mat b[max_terms];

void trans(mat a[],mat b[]){
    int row_term[a[0].col];
    int start[a[0].col];
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].val=a[0].val;

    for(int i=0;i<a[0].col;i++){
        row_term[i]=0;
    }
    for (int i=1;i<a[0].val;i++){
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

int main() {
    // 建立稀疏矩陣：3x3，有3個非零元素
    a[0].row = 3;  a[0].col = 3;  a[0].val = 3;
    a[1].row = 0;  a[1].col = 2;  a[1].val = 5;
    a[2].row = 1;  a[2].col = 1;  a[2].val = 8;
    a[3].row = 2;  a[3].col = 2;  a[3].val = 3;

    printf("原始稀疏矩陣：\n");
    print_matrix(a);

    trans(a, b);

    printf("\n轉置後的稀疏矩陣：\n");
    print_matrix(b);

    return 0;
}
