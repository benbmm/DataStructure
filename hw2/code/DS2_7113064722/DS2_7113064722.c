#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

int palindrome(int n,node* head){
    if (n%2){
        return 0;
    }
    node *prev=NULL,*next=NULL,*curr=head;
    for(int i=0;i<n/2;i++){
        curr=curr->next;
    }
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    node *head2=prev;
    for(int i=0;i<n/2;i++){
        if(head->val!=head2->val){
            return 0;
        }
        head=head->next;
        head2=head2->next;
    }
    return 0;
}

void printList(struct ListNode* head, FILE *out) {
    while (head != NULL) {
        fprintf(out, "%d ", head->val);
        head = head->next;
    }
    fprintf(out, "\n");
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
        int n, m;
        fscanf(inputFile, "%d", &n);

        struct ListNode *l1 = NULL, *l2 = NULL, *temp, *tail;

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

        // 讀取第二條鏈表
        fscanf(inputFile, "%d", &m);
        for (int i = 0; i < m; i++) {
            int val;
            fscanf(inputFile, "%d", &val);
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = val;
            temp->next = NULL;

            if (l2 == NULL) {
                l2 = temp;  // 如果是第一個節點
            } else {
                tail->next = temp;  // 把新節點連接到鏈表尾部
            }
            tail = temp;  // 更新尾部指針
        }

        // 合併並寫入結果
        struct ListNode* mergedList = mergeTwoLists(l1, l2);
        printList(mergedList, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
