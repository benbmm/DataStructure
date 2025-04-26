#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* current = dummy;
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

    if (l1 != NULL) {
        current->next = l1;
    } else {
        current->next = l2;
    }

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
    fscanf(inputFile, "%d", &T);

    while (T--) {
        int n, m;
        fscanf(inputFile, "%d", &n);

        struct ListNode *l1 = NULL, *l2 = NULL, *temp, *tail;

        for (int i = 0; i < n; i++) {
            int val;
            fscanf(inputFile, "%d", &val);
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = val;
            temp->next = NULL;
            
            if (l1 == NULL) {
                l1 = temp;  
            } else {
                tail->next = temp;  
            }
            tail = temp;  
        }

        fscanf(inputFile, "%d", &m);
        for (int i = 0; i < m; i++) {
            int val;
            fscanf(inputFile, "%d", &val);
            temp = (struct ListNode*)malloc(sizeof(struct ListNode));
            temp->val = val;
            temp->next = NULL;

            if (l2 == NULL) {
                l2 = temp;  
            } else {
                tail->next = temp;  
            }
            tail = temp;  
        }

        struct ListNode* mergedList = mergeTwoLists(l1, l2);
        printList(mergedList, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
