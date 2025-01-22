#include <stdio.h>
#include <stdlib.h>
 
typedef struct NODE {
    int value;
    struct NODE *next;
} node;
 
void addll(node **head, node **tail) {
    int num;
    scanf("%d", &num);
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = num;
    newnode->next = NULL;
 
    if (*head == NULL) {
        *head = newnode;
        *tail = newnode;
    } else {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}
 
void display(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}
 
void printsum(node **head, node **tail, int k) {
    int c = 0;
    node *temp = *head;
    
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    
 
    temp = *head;
    for (int i = 0; i < c - k; i++) {
        temp = temp->next;
    }
 
    int total = 0;
    while (temp != NULL) {
        total += temp->value;
        temp = temp->next;
    }
    printf("%d\n", total);
}
 
int main() {
    printf("Enter number of operations: ");
    int nop;
    scanf("%d", &nop);
 
    printf("Enter k: ");
    int k;
    scanf("%d", &k);
 
    node *head = NULL;
    node *tail = head;
 
    while (nop) {
        printf("Enter choice: ");
        char ch;
        scanf("\n%c", &ch);
 
        switch (ch) {
            case 'A':
                addll(&head, &tail);
                break;
            case 'S':
                printsum(&head, &tail, k);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        nop--;
    }
 
    return 0;
}