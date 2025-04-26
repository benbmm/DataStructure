#include <stdio.h>
#include <stdlib.h>

// Node structure as specified in the problem
struct Node {
    int order, num;
    struct Node *next, *prev;
};

// LinkedList structure as specified in the problem
struct LinkedList {
    struct Node *head;
};

// Function to create a new node with given order and number
struct Node* createNode(int order, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->order = order;
    newNode->num = num;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to initialize the circular linked list with cards
struct LinkedList* initializeList(int* cards, int size) {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    if (size == 0) {
        list->head = NULL;
        return list;
    }
    
    // Create the first node
    struct Node* firstNode = createNode(1, cards[0]);
    list->head = firstNode;
    
    struct Node* prevNode = firstNode;
    
    // Create other nodes and link them
    for (int i = 1; i < size; i++) {
        struct Node* newNode = createNode(i + 1, cards[i]);
        prevNode->next = newNode;
        newNode->prev = prevNode;
        prevNode = newNode;
    }
    
    // Complete the circular structure
    prevNode->next = list->head;
    list->head->prev = prevNode;
    
    return list;
}

// Function to free memory allocated for the linked list
void freeList(struct LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        free(list);
        return;
    }
    
    // If there's only one node
    if (list->head->next == list->head) {
        free(list->head);
        free(list);
        return;
    }
    
    struct Node* current = list->head;
    struct Node* start = current;
    struct Node* temp;
    
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != start);
    
    free(list);
}

// Main function to solve the problem
void solveCardMasterProblem(int* cards, int m) {
    if (m <= 1) {
        printf("0\n");
        return;
    }
    
    // Initialize the circular linked list
    struct LinkedList* cardList = initializeList(cards, m);
    
    // Array to store discarded orders
    int* discardedOrders = (int*)malloc(m * sizeof(int));
    int discardCount = 0;
    
    // Step 1: Process the first two cards to get the initial GCD
    struct Node* current = cardList->head->next;  // Start with the second card
    int lastGcd = gcd(cardList->head->num, current->num);
    current = current->next;  // Move to the third card
    
    // Step 2: Process remaining cards
    while (1) {
        if (cardList->head->next == cardList->head) {
            // Only one card left
            break;
        }
        
        int anyDiscarded = 0;  // Flag to check if any card was discarded in a full pass
        struct Node* startNode = current;
        
        do {
            struct Node* prevNode = current->prev;
            int currentGcd = gcd(prevNode->num, current->num);
            
            if (currentGcd == lastGcd && currentGcd > 1) {
                // Save this card's order before discarding
                discardedOrders[discardCount++] = current->order;
                
                // Remove this card from the list
                prevNode->next = current->next;
                current->next->prev = prevNode;
                
                struct Node* tempNode = current;
                current = current->next;
                
                // If we removed head, update it
                if (tempNode == cardList->head) {
                    cardList->head = current;
                }
                
                free(tempNode);
                anyDiscarded = 1;
                
                // Don't update lastGcd after discarding
                break;
            } else {
                // Update the lastGcd and move to next card
                lastGcd = currentGcd;
                current = current->next;
            }
        } while (current != startNode);
        
        // If we've gone through all cards and couldn't discard any, we're done
        if (!anyDiscarded) {
            break;
        }
    }
    
    // Output the result
    printf("%d\n", discardCount);
    if (discardCount > 0) {
        for (int i = 0; i < discardCount; i++) {
            printf("%d ", discardedOrders[i]);
        }
        printf("\n");
    }
    
    // Clean up memory
    free(discardedOrders);
    freeList(cardList);
}

// Function to run a test case
void runTestCase(int* cards, int m) {
    printf("Input:\n");
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", cards[i]);
    }
    printf("\n\nOutput:\n");
    
    solveCardMasterProblem(cards, m);
}

int main() {
    // Test case 1
    int testCase1[] = {12, 18, 24, 30, 40, 50};
    int m1 = 6;
    
    printf("=== Test Case 1 ===\n");
    runTestCase(testCase1, m1);
    
    printf("\n=== Test Case 2 ===\n");
    
    // Test case 2
    int testCase2[] = {7, 14, 21, 28};
    int m2 = 4;
    
    runTestCase(testCase2, m2);
    
    return 0;
}