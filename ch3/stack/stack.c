#include <stdio.h>
#include <stdlib.h>
#define max_stack 100

int stack[max_stack];
int top=-1;

void pop(int x){
    if (top>=max_stack-1){
        printf("stack is full");
        exit(1);
    }
    stack[++top]=x;
}
int push(){
    if (top==-1){
        printf("stack is empty");
        exit(1);
    }
    return stack[top--];
}
void isEmpty(){
    if (top==-1){
        return 1;
    }else{
        return 0;
    }
}