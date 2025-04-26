#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

node* delete_duplicates(node* head){
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->val==temp->next->val){
            struct ListNode* duplicate = temp->next;
            temp->next=temp->next->next;
            free(duplicate);
        }else{
            temp=temp->next;
        }
    }
    return head;
}

void printList(node* head, FILE *out) {
    while (head != NULL) {
        fprintf(out, "%d ", head->val);
        head = head->next;
    }
    fprintf(out, "\n");
}

int main() {
    FILE *inputFile = fopen("testcase3.txt", "r");
    FILE *outputFile = fopen("output3.txt", "w");

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
        printList(delete_duplicates(l1),outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
