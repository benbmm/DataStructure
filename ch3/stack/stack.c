#include <stdio.h>
#include <stdlib.h>
#define max_stack 100

int stack[max_stack];
int top=-1;

void push(int x){
    if (top>=max_stack-1){
        printf("stack is full");
        exit(1);
    }
    stack[++top]=x;
}
int pop(){
    if (top==-1){
        printf("stack is empty");
        exit(1);
    }
    return stack[top--];
}
int isEmpty(){
    if (top==-1){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    printf("Pushing 3, 5, 7 into stack...\n");
    push(3);
    push(5);
    push(7);

    printf("Popping elements:\n");
    while (!isEmpty()) {
        int val = pop();
        printf("Popped: %d\n", val);
    }

    printf("Trying to pop from empty stack (should exit)...\n");
    pop(); // 會觸發錯誤並 exit

    return 0;
}

