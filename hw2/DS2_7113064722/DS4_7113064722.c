#include <stdio.h>
#include <stdlib.h>

typedef struct output {
    int val;
    struct output *next;
}output;

typedef struct Node {
    int order,num;
    struct Node *next,*prev;
}node;

typedef struct LinkedList{
    node* head;
}linkedlist;

int gcd(int x, int y) {
    if (x < y) {
        return gcd(y, x);
    } else if (y == 0) {
        return x;
    } else {
        return gcd(y, x % y);
    }
}

output* Card_Master(node* head) {
    output* out_head = (output*)malloc(sizeof(output));
    out_head->val = 0; 
    out_head->next = NULL;
    output* out_tail = out_head;
    
    if (head == head->next || head == head->next->next) {
        return out_head; 
    }
    
    node* current = head->next->next; 
    int lastGcd = gcd(head->num, head->next->num);  
    
    int anyDiscarded;
    do {
        anyDiscarded = 0;
        node* startNode = current;
        
        do {
            node* prevNode = current->prev;
            int currentGcd = gcd(prevNode->num, current->num);
            
            if (currentGcd == lastGcd && currentGcd > 1) {
                out_head->val++; 
                output* temp = (output*)malloc(sizeof(output));
                temp->val = current->order;
                temp->next = NULL;
                out_tail->next = temp;
                out_tail = temp;
                
                prevNode->next = current->next;
                current->next->prev = prevNode;
                
                node* toDelete = current;
                current = current->next;
                free(toDelete);
                
                anyDiscarded = 1;
                break;
            } else {
                lastGcd = currentGcd;
                current = current->next;
            }
        } while (current != startNode);
        
    } while (anyDiscarded && head != head->next);
    
    return out_head;
}

void printList(output* head, FILE *out) {
    fprintf(out,"%d ",head->val);
    head=head->next;
    while (head != NULL) {
        fprintf(out, "%d ", head->val);
        head = head->next;
    }
    fprintf(out, "\n");
}

int main() {
    FILE *inputFile = fopen("testcase4.txt", "r");
    FILE *outputFile = fopen("output4.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("無法開啟檔案！\n");
        return -1;
    }

    int T;
    fscanf(inputFile, "%d", &T); 

    while (T--) {
        int n;
        fscanf(inputFile, "%d", &n);
        node *l1 = NULL, *temp, *tail,*prev=NULL;

        for (int i = 0; i < n; i++) {
            int val;
            fscanf(inputFile, "%d", &val);
            temp = (node*)malloc(sizeof(node));
            temp->num = val;
            temp->order=i+1;
            temp->next = NULL;
            temp->prev=prev;
            prev=temp;
            
            if (l1 == NULL) {
                l1 = temp;
            } else {
                tail->next = temp;
            }
            tail = temp;
        }
        l1->prev=tail;
        tail->next = l1;
        printList(Card_Master(l1),outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
