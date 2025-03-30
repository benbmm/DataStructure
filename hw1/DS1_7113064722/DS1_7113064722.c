#include <stdio.h>
#include <stdlib.h>

#define max_terms 100

typedef struct{
    int top;
    float terms[max_terms];
    int id;
}stack;

void stack_init(stack *c,int id){
    c->id=id;
    c->top=-1;
}

int stack_is_empty(stack *c){
    if (c->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void stack_push(stack *c,float x){
    if((*c).top>=max_terms-1){
        printf("stack_%d is full",c->id);
        exit(1);
    }
    c->terms[++(c->top)]=x;
}

float stack_pop(stack*c){
    if(stack_is_empty(c)){
        printf("stack_%d is full",c->id);
        exit(1);
    }else{
        return c->terms[(c->top)--];
    }
}