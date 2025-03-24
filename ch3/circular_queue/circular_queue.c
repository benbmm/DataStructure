#include <stdio.h>
#include <stdlib.h>
#define max_queue 6

int queue[max_queue];
int rear=0;
int front=0;

void addq(int x){
    rear=(rear+1)%max_queue;
    if (rear==front){
        printf("queue is full");
        exit(1);
    }
    queue[rear]=x;
}
int deleteq(){
    if (front==rear){
        printf("queue is empty");
        exit(1);
    }
    front=(front+1)%max_queue;
    return queue[front];
}
int isEmpty(){
    if(rear==front){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    for (int i = 1; i <= 5; i++) {
        printf("Adding: %d\n", i);
        addq(i);
    }

    printf("Deleting two items...\n");
    printf("Deleted: %d\n", deleteq());
    printf("Deleted: %d\n", deleteq());

    printf("Adding 6, 7 (should work if circular works)\n");
    addq(6);
    addq(7);

    printf("Dequeuing all:\n");
    while (!isEmpty()) {
        printf("Deleted: %d\n", deleteq());
    }

    return 0;
}
