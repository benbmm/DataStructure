#include <stdio.h>
#include <stdlib.h>

typedef struct poly{
    int exp;
    float coef;
    struct poly* next;
}poly;

poly** init_head_or_tail(int n){
    poly** temp=(poly**)malloc(sizeof(poly*)*n);
    for (int i=0;i<n;i++){
        temp[i]=NULL;
    }
    return temp;
}

void attach(poly** head,poly** tail,float coef,int exp){
    poly* temp=(poly*)malloc(sizeof(poly));
    if (temp==NULL){
        printf("malloc error");
        exit(1);
    }
    temp->coef=coef;
    temp->exp=exp;
    temp->next=NULL;
    if ((*head)==NULL){
        (*head)=temp;
        (*tail)=temp;
    }else{
        if((*tail)->exp <= temp->exp){
            printf("attach order error");
            exit(1);
        }
        (*tail)->next=temp;
        (*tail)=temp;
    }
}

int compare(poly* node_a,poly* node_b){
    if(node_a->exp > node_b->exp){
        return 1;
    }else if(node_a->exp == node_b->exp){
        return 0;
    }else{
        return -1;
    }
}

void padd(poly** a,poly** b,poly** head_c,poly** tail_c){
    poly* temp_a=*a;
    poly* temp_b=*b;
    int sum;
    while(temp_a!=NULL && temp_b!=NULL){
        switch (compare(temp_a,temp_b))
        {
        case 1:
            attach(head_c,tail_c,temp_a->coef,temp_a->exp);
            temp_a=temp_a->next;
            break;
        case 0:
            sum=temp_a->coef+temp_b->coef;
            if(sum){
                attach(head_c,tail_c,sum,temp_a->exp);
            }
            temp_a=temp_a->next;
            temp_b=temp_b->next;
            break;
        case -1:
            attach(head_c,tail_c,temp_b->coef,temp_b->exp);
            temp_b=temp_b->next;
            break;
        default:
            break;
        }
    }
    while (temp_a != NULL) {
        attach(head_c, tail_c, temp_a->coef, temp_a->exp);
        temp_a = temp_a->next;
    }
    while (temp_b != NULL) {
        attach(head_c, tail_c, temp_b->coef, temp_b->exp);
        temp_b = temp_b->next;
    }
}
void print_poly(poly** head_c){
    poly* temp=*head_c;
    while(temp->next!=NULL){
        printf("%gx^%d + ",temp->coef,temp->exp);
        temp=temp->next;
    }
    if (temp->exp==0){
        printf("%g",temp->coef);
    }else{
        printf("%gx^%d",temp->coef,temp->exp);
    }
    printf("\n");
}
int main(){
    poly** head=init_head_or_tail(3);
    poly** tail=init_head_or_tail(3);
    attach(&head[0],&tail[0],10,567);
    attach(&head[0],&tail[0],127,5);
    attach(&head[0],&tail[0],1,2);
    attach(&head[0],&tail[0],1,1);
    attach(&head[0],&tail[0],777,0);
    print_poly(&head[0]);

    attach(&head[1],&tail[1],100,1028);
    attach(&head[1],&tail[1],1,48);
    attach(&head[1],&tail[1],50,6);
    attach(&head[1],&tail[1],1,5);
    attach(&head[1],&tail[1],1,2);
    attach(&head[1],&tail[1],9,0);
    print_poly(&head[1]);

    padd(&head[0],&head[1],&head[2],&tail[2]);
    print_poly(&head[2]);

}