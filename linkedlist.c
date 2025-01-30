#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Global variables
struct node *start = NULL, *end = NULL;
int count = 0;

// Insert at the beginning
void insert_at_beginning() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    int input;
    printf("Enter value to insert at the beginning: ");
    scanf("%d", &input);
    
    newnode->data = input;
    newnode->next = start;
    start = newnode;

    if (end == NULL) { // If list was empty, set end as well
        end = newnode;
    }
    
    count++;
    printf("Value added at beginning successfully.\n");
}

// Insert at the end
void insert_at_end() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    int input;
    printf("Enter value to insert at the end: ");
    scanf("%d", &input);
    
    newnode->data = input;
    newnode->next = NULL;

    if (start == NULL) {
        start = end = newnode;
    } else {
        end->next = newnode;
        end = newnode;
    }
    
    count++;
    printf("Value added at end successfully.\n");
}

// Insert at kth position
void insert_at_kth() {
    int pos, input, i = 1;
    struct node *newnode, *temp = start;
    
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count + 1) {
        printf("Invalid position!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("Enter value to insert at position %d: ", pos);
    scanf("%d", &input);
    
    newnode->data = input;
    
    if (pos == 1) { // Insert at the beginning
        newnode->next = start;
        start = newnode;
        if (end == NULL) {
            end = newnode;
        }
    } else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == NULL) {
            end = newnode;
        }
    }
    
    count++;
    printf("Value inserted at position %d successfully.\n", pos);
}

// Delete at beginning
void delete_at_beginning() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct node *temp = start;
    start = start->next;
    free(temp);
    
    count--;
    if (start == NULL) { // If list becomes empty, reset end
        end = NULL;
    }
    
    printf("Value deleted at beginning successfully.\n");
}

// Delete at end
void delete_at_end() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = start;
    if (start == end) { // Only one element in the list
        free(start);
        start = end = NULL;
    } else {
        while (temp->next != end) {
            temp = temp->next;
        }
        free(end);
        temp->next = NULL;
        end = temp;
    }
    
    count--;
    printf("Value deleted at end successfully.\n");
}

// Delete at kth position
void delete_at_kth() {
    int pos, i = 1;
    struct node *temp = start, *temp2;
    
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) { // Delete at the beginning
        start = start->next;
        free(temp);
        if (start == NULL) {
            end = NULL;
        }
    } else {
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        if (temp2 == end) {
            end = temp;
        }
        free(temp2);
    }
    
    count--;
    printf("Value deleted at position %d successfully.\n", pos);
}

// Display all elements
void display() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct node *temp = start;
    printf("Elements in Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Exit program
void exit_program() {
    printf("Exiting program. Goodbye!\n");
    exit(0);
}

int main() {
    int choice, option;
    
    while (1) { // Loop for repetitive execution
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at kth Position\n");
        printf("4. Delete First Element\n");
        printf("5. Delete Last Element\n");
        printf("6. Delete kth Element\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insert_at_beginning(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_kth(); break;
            case 4: delete_at_beginning(); break;
            case 5: delete_at_end(); break;
            case 6: delete_at_kth(); break;
            case 7: display(); break;
            case 8: 
                printf("Are you sure you want to exit? (1: Yes, 0: No): ");
                scanf("%d", &option);
                if (option == 1) {
                    exit_program();
                }
                break;
            default: printf("Invalid choice! Please enter a valid number.\n");
        }

        // Ask user whether to return to menu or exit
        printf("\nPress 1 to return to the main menu or 0 to exit: ");
        scanf("%d", &option);
        if (option == 0) {
            exit_program();
        }
    }
    return 0;
}

