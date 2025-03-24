#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct{
    int col;
    int row;
    int val;
}mat;
mat a[MAX_TERMS];
mat b[MAX_TERMS];



void trans(mat a[],mat b[]){
    int current_b;
    b[0].col=a[0].row;
    b[0].row=a[0].col;
    b[0].val=a[0].val;
    if(a[0].val>0){
        current_b=1;
        for(int i=0;i<a[0].col;i++){
            for(int j=0;j<=a[0].val;j++){
                if (a[j].col==i){
                    b[current_b].row=a[j].col;
                    b[current_b].col=a[j].row;
                    b[current_b].val=a[j].val;
                    current_b++;
                }
            }
        }
    }else{
        printf("a is empty");
        exit(1);
    }
}

void print_matrix(const mat m[]) {
    printf("row\tcol\tval\n");
    for (int i = 0; i <= m[0].val; i++) {
        printf("%d\t%d\t%d\n", m[i].row, m[i].col, m[i].val);
    }
}

int main() {
    // 建立一個 3x3 矩陣，有3個非零元素
    // 原始矩陣 (以稀疏格式表示)
    // | 0 0 5 |
    // | 0 8 0 |
    // | 0 0 3 |
    a[0].row = 3;  // rows
    a[0].col = 3;  // cols
    a[0].val = 3;  // number of non-zero elements

    a[1].row = 0; a[1].col = 2; a[1].val = 5;
    a[2].row = 1; a[2].col = 1; a[2].val = 8;
    a[3].row = 2; a[3].col = 2; a[3].val = 3;

    printf("原始稀疏矩陣：\n");
    print_matrix(a);

    trans(a, b);

    printf("\n轉置後的稀疏矩陣：\n");
    print_matrix(b);

    return 0;
}