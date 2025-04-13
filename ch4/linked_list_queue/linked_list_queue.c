#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node** init_head_or_tail(int n){
    node** temp=(node**)malloc(sizeof(node*)*n);
    for(int i=0;i<n;i++){
        temp[i]=NULL;
    }
    return temp;
}

void enqueue(node** head,node** tail,int x){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    if((*head)==NULL){
        (*head)=temp;
        (*tail)=temp;
    }else{
        (*tail)->next=temp;
        (*tail)=temp;
    }
}

int dequeue(node** head,node** tail){
    if((*head)==NULL){
        printf("queue is enpty\n");
        exit(1);
    }else{
        int x=(*head)->data;
        node* temp=(*head);
        (*head)=(*head)->next;
        if((*head)==NULL){
            (*tail)=NULL;
        }
        free(temp);
        return x;
    }
}

void print_queue(node* head){
    node* current = head;
    printf("Queue: ");
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    int num_queues = 3;
    node** heads = init_head_or_tail(num_queues);
    node** tails = init_head_or_tail(num_queues);

    // 初始化不同 queue
    enqueue(&heads[0], &tails[0], 10);
    enqueue(&heads[0], &tails[0], 20);
    enqueue(&heads[0], &tails[0], 30);

    enqueue(&heads[1], &tails[1], 100);
    enqueue(&heads[1], &tails[1], 200);

    enqueue(&heads[2], &tails[2], 999);

    // 印出全部 queue 狀態
    for(int i = 0; i < num_queues; i++){
        printf("Queue %d: ", i);
        print_queue(heads[i]);
    }

    // Dequeue 每個 queue 一次
    for(int i = 0; i < num_queues; i++){
        if(heads[i] != NULL){
            int val = dequeue(&heads[i], &tails[i]);
            printf("Dequeued from queue %d: %d\n", i, val);
        }
    }

    // 印出剩餘狀態
    printf("\nAfter one dequeue each:\n");
    for(int i = 0; i < num_queues; i++){
        printf("Queue %d: ", i);
        print_queue(heads[i]);
    }

    // 釋放記憶體
    free(heads);
    free(tails);

    return 0;
}