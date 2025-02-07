#include <stdio.h> 
#include <stdlib.h>
 
struct Node { 
    int data; 
    struct Node *prev, *next; 
}; 
 
struct Node *head = NULL; 
 
void insertAtBeginning(int data) { 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->prev = NULL; 
    newNode->next = head; 
 
    if (head != NULL) 
        head->prev = newNode; 
 
    head = newNode; 
} 
 
void insertAtEnd(int data) { 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
 
    if (head == NULL) { 
        newNode->prev = NULL; 
        head = newNode; 
        return; 
    } 
 
    struct Node *temp = head; 
    while (temp->next != NULL) 
        temp = temp->next; 
 
    temp->next = newNode; 
    newNode->prev = temp; 
} 
 
void insertAtKth(int data, int k) { 
    if (k == 1) { 
        insertAtBeginning(data); 
        return; 
    } 
 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->data = data; 
 
    struct Node *temp = head; 
    for (int i = 1; temp != NULL && i < k - 1; i++) 
        temp = temp->next; 
 
    if (temp == NULL) { 
        printf("Position out of range!\n"); 
        free(newNode); 
        return; 
    } 
 
    newNode->next = temp->next; 
    newNode->prev = temp; 
 
    if (temp->next != NULL) 
        temp->next->prev = newNode; 
 
    temp->next = newNode; 
} 
 
void deleteAtBeginning() { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node *temp = head; 
    head = head->next; 
 
    if (head != NULL) 
        head->prev = NULL; 
 
    free(temp); 
} 
 
void deleteAtEnd() { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node *temp = head; 
    if (temp->next == NULL) { 
        free(temp); 
        head = NULL; 
        return; 
    } 
 
    while (temp->next != NULL) 
        temp = temp->next; 
 
    temp->prev->next = NULL; 
    free(temp); 
} 
 
void deleteAtKth(int k) { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node *temp = head; 
 
    if (k == 1) { 
        deleteAtBeginning(); 
        return; 
    } 
 
    for (int i = 1; temp != NULL && i < k; i++) 
        temp = temp->next; 
 
    if (temp == NULL) { 
        printf("Position out of range!\n"); 
        return; 
    } 
 
    if (temp->next != NULL) 
        temp->next->prev = temp->prev; 
 
    if (temp->prev != NULL) 
        temp->prev->next = temp->next; 
 
    free(temp); 
} 
 
void displayList() { 
    if (head == NULL) { 
        printf("List is empty!\n"); 
        return; 
    } 
 
    struct Node *temp = head; 
    printf("Doubly Linked List: "); 
    while (temp != NULL) { 
        printf("%d <-> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
int main() { 
    int choice, data, position; 
 
    do { 
        printf("\nDoubly Linked List Operations:\n"); 
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Kth position\n"); 
        printf("4. Delete from Beginning\n5. Delete from End\n6. Delete from Kth position\n"); 
        printf("7. Display List\n8. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertAtBeginning(data); 
                break; 
            case 2: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                insertAtEnd(data); 
                break; 
            case 3: 
                printf("Enter data: "); 
                scanf("%d", &data); 
                printf("Enter position: "); 
                scanf("%d", &position); 
                insertAtKth(data, position); 
                break; 
            case 4: 
                deleteAtBeginning(); 
                break; 
            case 5: 
                deleteAtEnd(); 
                break; 
            case 6: 
                printf("Enter position: "); 
                scanf("%d", &position); 
                deleteAtKth(position); 
                break; 
            case 7: 
                displayList(); 
                break; 
            case 8: 
                printf("Exiting program...\n"); 
                break; 
            default: 
                printf("Invalid choice! Please enter a valid option.\n"); 
        } 
    } while (choice != 8); 
 
    return 0; 
} 
