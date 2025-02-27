#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL || (*head)->exp < exp) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head, *prev = NULL;
        while (temp != NULL && temp->exp > exp) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->exp == exp) {
            temp->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp;
            if (prev != NULL) prev->next = newNode;
        }
    }
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* sum = NULL;
    while (p1 != NULL || p2 != NULL) {
        if (p2 == NULL || (p1 != NULL && p1->exp > p2->exp)) {
            insertTerm(&sum, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1 == NULL || (p2 != NULL && p2->exp > p1->exp)) {
            insertTerm(&sum, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insertTerm(&sum, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return sum;
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    int first = 1;
    while (temp != NULL) {
        if (!first && temp->coeff > 0) printf(" + ");
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        first = 0;
    }
    printf("\n");
}

int getMaxExponent(Node* head) {
    return (head != NULL) ? head->exp : 0;
}

int main() {
    Node* p1 = NULL, *p2 = NULL;
    int n1, n2, coeff, exp;
    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter terms (coefficient exponent):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p1, coeff, exp);
    }
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter terms (coefficient exponent):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&p2, coeff, exp);
    }
    
    Node* sum = addPolynomials(p1, p2);
    
    printf("Sum of polynomials:\n");
    displayPolynomial(sum);
    printf("Number of dials needed: %d\n", getMaxExponent(sum));
    
    return 0;
}