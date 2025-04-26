#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

int palindrome(int n,node* head){
    if(head==NULL || head->next==NULL){
        return 1;
    }
    node *fast=head,*slow=head;
    while(fast != NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node *prev=NULL,*next=NULL,*curr=slow;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    node *head2=prev;
    while(head2!=NULL){
        if(head->val!=head2->val){
            return 0;
        }
        head=head->next;
        head2=head2->next;
    }
    return 1;
}

int main() {
    FILE *inputFile = fopen("testcase2.txt", "r");
    FILE *outputFile = fopen("output2.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    int T;
    fscanf(inputFile, "%d", &T); // 讀取測試案例數量

    while (T--) {
        int n;
        fscanf(inputFile, "%d", &n);

        struct ListNode *l1 = NULL, *temp, *tail;

        // 讀取第一條鏈表
        for (int i = 0; i < n; i++) {
            int val;
            fscanf(inputFile, "%d", &val);
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = val;
            temp->next = NULL;
            
            if (l1 == NULL) {
                l1 = temp;  // 如果是第一個節點
            } else {
                tail->next = temp;  // 把新節點連接到鏈表尾部
            }
            tail = temp;  // 更新尾部指針
        }

        fprintf(outputFile,"%d\n",palindrome(n,l1));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
