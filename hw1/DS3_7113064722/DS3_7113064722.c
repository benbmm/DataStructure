#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int data;
    struct link *next;
}link;

link** init(int x){
    link** lists=(link**)malloc(x*sizeof(link*));
    for (int i=0;i<x;i++){
        lists[i]=NULL;
    }
    return lists;
}

void input(link** head,int x){
    link* a = (link*)malloc(sizeof(link));
    a->data=x;
    a->next=NULL;
    if(*head==NULL){
        *head=a;
    }else{
        link* b=*head;
        while(b->next!=NULL){
            b=b->next;
        }
        b->next=a;
    }
}