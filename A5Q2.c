#include <stdio.h>
#include <stdlib.h>

struct stack {
    int token;
    struct stack* next;
};

struct stack *top1 = NULL, *top2 = NULL;

void push(struct stack** top, int x) {
    struct stack* new = (struct stack*)malloc(sizeof(struct stack));
    if (new == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    new->token = x;
    new->next = *top;
    *top = new;
}

int pop(struct stack** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct stack* temp = *top;
    int x = temp->token;
    *top = (*top)->next;
    free(temp);
    return x;
}

void enqueue(int x) {
    push(&top1, x);
}

int dequeue() {
    if (top2 == NULL) {
        while (top1 != NULL) {
            push(&top2, pop(&top1));
        }
    }
    if (top2 == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(&top2);
}

int main() {
    int choice, token = 1;
    while (1) {
        printf("\nChoose:\n1. Add token to the queue\n2. Remove token from the queue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                enqueue(token++);
                printf("Token %d added to the queue.\n", token - 1);
                break;
            case 2:
                {
                    int removedToken = dequeue();
                    if (removedToken != -1) {
                        printf("Dequeued Token: %d\n", removedToken);
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    return 0;
}
