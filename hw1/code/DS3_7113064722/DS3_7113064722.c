#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link{
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

void switch_place(link** head,int x,int y){
    link* a=*head;
    link* left=NULL;
    link* right=NULL;

    int index=1;
    while(index<=y){
        if (a==NULL){
            break;
        }
        if(index==x){
            left=a;
        }
        if(index==y){
            right=a;
        }
        a=a->next;
        index++;
    }
    if (left!=NULL && right!=NULL){
        int temp = left->data;
        left->data=right->data;
        right->data=temp;
    }else{
        printf("Out of range\n");
        exit(1);
    }

}

void print_list_to_file(link* head, FILE* out) {
    while (head != NULL) {
        fprintf(out, "%d", head->data);
        if (head->next != NULL) {
            fprintf(out, " ");
        }
        head = head->next;
    }
    fprintf(out, "\n");
}

void free_list(link* head) {
    while (head != NULL) {
        link* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* in = fopen("test3.txt", "r");
    FILE* out = fopen("output3.txt", "w");
    if (in == NULL || out == NULL) {
        perror("File error");
        return 1;
    }

    int list_count;
    fscanf(in, "%d", &list_count);
    link** lists = init(list_count);

    for (int i = 0; i < list_count; i++) {
        int x, y;
        fscanf(in, "%d %d", &x, &y);

        char line[1024];
        fgetc(in);  // 吃掉前一行的換行
        fgets(line, sizeof(line), in);

        char* token = strtok(line, " ");
        while (token != NULL) {
            int val = atoi(token);
            input(&lists[i], val);
            token = strtok(NULL, " ");
        }

        switch_place(&lists[i], x, y);
        print_list_to_file(lists[i], out);
        free_list(lists[i]);
    }

    free(lists);
    fclose(in);
    fclose(out);
    return 0;
}