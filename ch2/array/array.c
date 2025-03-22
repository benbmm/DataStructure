#include <stdio.h>
void print1(int *p,int row){
    for(int i=0;i<row;i++){
        printf("(%08u,%5d)",p+i,*p+i);
    }
}
int main(void){
    int one[]={1,2,3,4,5};
    print1(&one[0],5);
    return 0;
}

