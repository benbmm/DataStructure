#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_terms 100

typedef struct {
    int top;
    int terms[max_terms];
} stack;

stack s1, s2;

void stack_init(stack *c) {
    c->top = -1;
}

int stack_is_empty(stack *c) {
    return (c->top == -1);
}

void stack_push(stack *c, int x) {
    if (c->top >= max_terms - 1) {
        printf("queue is full\n");
        exit(1);
    }
    c->terms[++(c->top)] = x;
}

int stack_pop(stack *c) {
    if (stack_is_empty(c)) {
        printf("queue is empty\n");
        exit(1);
    }
    return c->terms[(c->top)--];
}

void push(int x) {
    while (!stack_is_empty(&s2)) {
        int y = stack_pop(&s2);
        stack_push(&s1, y);
    }
    stack_push(&s1, x);
}

int pop() {
    while (!stack_is_empty(&s1)) {
        int y = stack_pop(&s1);
        stack_push(&s2, y);
    }
    return stack_pop(&s2);
}

int peek() {
    while (!stack_is_empty(&s1)) {
        int y = stack_pop(&s1);
        stack_push(&s2, y);
    }
    if (!stack_is_empty(&s2)) {
        return s2.terms[s2.top];
    } else {
        printf("queue is empty\n");
        exit(1);
    }
}

int empty() {
    return (stack_is_empty(&s1) && stack_is_empty(&s2));
}

int main() {
    FILE *input = fopen("test1.txt", "r");
    FILE *output = fopen("output1.txt", "w");
    if (!input || !output) {
        printf("Failed to open file\n");
        return 1;
    }

    stack_init(&s1);
    stack_init(&s2);

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), input)) {
        if (strncmp(buffer, "push", 4) == 0) {
            int val;
            sscanf(buffer + 5, "%d", &val);
            push(val);
        } else if (strncmp(buffer, "pop", 3) == 0) {
            int val = pop();
            //fprintf(output, "%d\n", val);
        } else if (strncmp(buffer, "peek", 4) == 0) {
            int val = peek();
            fprintf(output, "%d\n", val);
        } else if (strncmp(buffer, "empty", 5) == 0) {
            int val = empty();
            fprintf(output, "%s\n", val ? "true" : "false");
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
