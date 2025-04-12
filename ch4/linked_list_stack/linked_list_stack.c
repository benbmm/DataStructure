#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;
typedef node* list_ptr;

list_ptr* init(int n){
    list_ptr* temp=(list_ptr*)malloc(sizeof(list_ptr)*n);
    for(int i=0;i<n;i++){
        temp[i]=NULL;
    }
    return(temp);
}

void push(list_ptr* ptr,int x){
    list_ptr temp = (list_ptr)malloc(sizeof(node));
    if (temp==NULL){
        printf("malloc error");
        exit(1);
    }
    temp->data=x;
    temp->next=*ptr;
    *ptr=temp;
}

int pop(list_ptr* ptr){
    list_ptr temp=*ptr;
    int x=temp->data;
    *ptr=temp->next;
    free(temp);
    return x;
}
int main() {
    int n = 3;
    list_ptr* lists = init(n); // 建立 3 個 list

    push(&lists[0], 10);
    push(&lists[0], 20);
    push(&lists[1], 30);
    push(&lists[2], 40);
    push(&lists[2], 50);

    printf("pop from list 0: %d\n", pop(&lists[0])); // 應該是 20
    printf("pop from list 0: %d\n", pop(&lists[0])); // 應該是 10
    printf("pop from list 1: %d\n", pop(&lists[1])); // 應該是 30
    printf("pop from list 2: %d\n", pop(&lists[2])); // 應該是 50
    printf("pop from list 2: %d\n", pop(&lists[2])); // 應該是 40

    free(lists);
    return 0;
}