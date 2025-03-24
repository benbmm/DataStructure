#include <stdio.h>
#include <stdlib.h>
#define max_queue 100

int queue[max_queue];
int rear=-1;
int front=-1;

void addq(int x){
    if (rear>=max_queue-1){
        printf("queue is full");
        exit(1);
    }
    queue[++rear]=x;
}
int deleteq(){
    if (front==rear){
        printf("queue is empty");
        exit(1);
    }
    return queue[front++];
}
int isEmpty(){
    if(rear==front){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    printf("Adding 10, 20, 30 to queue...\n");
    addq(10);
    addq(20);
    addq(30);

    printf("Deleting elements from queue:\n");
    while (!isEmpty()) {
        int val = deleteq();
        printf("Deleted: %d\n", val);
    }

    printf("Trying to delete from empty queue (should exit)...\n");
    deleteq(); // 觸發錯誤

    return 0;
}
