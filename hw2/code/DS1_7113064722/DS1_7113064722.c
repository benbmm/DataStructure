#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // 建立一個虛擬的頭節點
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* current = dummy;

    // 合併兩個鏈表
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // 如果有剩餘的元素，將其接到合併鏈表後面
    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    // 返回合併後的鏈表
    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

void printList(struct ListNode* head, FILE *out) {
    while (head != NULL) {
        fprintf(out, "%d ", head->val);
        head = head->next;
    }
    fprintf(out, "\n");
}

int main() {
    FILE *inputFile = fopen("testcase1.txt", "r");
    FILE *outputFile = fopen("output1.txt", "w");

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
