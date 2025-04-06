#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_terms 100

typedef struct{
    int rear;
    int front;
    int terms[max_terms];
}queue;

queue q1,q2;

void q_init(queue *c){
    c->front=0;
    c->rear=0;
}

int q_is_empty(queue *c){
    return c->front==c->rear;
}

void q_push(queue *c,int x){
    c->rear=(c->rear+1)%max_terms;
    if (c->front==c->rear){
        printf("stack is full\n");
        exit(1);
    }
    c->terms[c->rear]=x;
}

int q_is_last(queue *c){
    return (c->front+1)%max_terms==c->rear;
}

int q_pop(queue *c){
    if (q_is_empty(c)){
        printf("stack is empty\n");
        exit(1);
    }
    c->front=(c->front+1)%max_terms;
    return c->terms[c->front];
}

int is_empty(){
    return(q_is_empty(&q1) && q_is_empty(&q2));
}

void push(int x){
    q_push(&q1,x);
}

int pop(){
    while(!q_is_last(&q1)){
        int x=q_pop(&q1);
        q_push(&q2,x);
    }
    int y=q_pop(&q1);
    while(!q_is_empty(&q2)){
        int z=q_pop(&q2);
        q_push(&q1,z);
    }
    return y;
}

int main(){
    FILE *input = fopen("test2.txt", "r");
    FILE *output= fopen("output2.txt","w");
    if (!input || !output) {
        printf("Failed to open file\n");
        return 1;
    }
    q_init(&q1);
    q_init(&q2);
    char buffer[100];
    while(fgets(buffer,sizeof(buffer),input)){
        if(strncmp("push",buffer,4)==0){
            int val;
            sscanf(buffer+5,"%d",&val);
            push(val);
        }
        else if(strncmp("pop",buffer,3)==0){
            int val=pop();
            //fprintf(output,"%d",val);
        }
        else if(strncmp("peek",buffer,4)==0){
            int val=q1.terms[q1.rear];
            fprintf(output,"%d\n",val);
        }
        else if (strncmp("empty",buffer,5)==0){
            if (is_empty()){
                fprintf(output,"true\n");
            }else{
                fprintf(output,"false\n");
            }
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}