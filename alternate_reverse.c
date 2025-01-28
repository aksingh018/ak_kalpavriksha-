#include<stdio.h>
#include<stdlib.h>

int flag=1;

typedef struct NODE
{
    int value;
    struct NODE *next;
}node;

node *temp = NULL;

void add_linked_list(node **head, node **tail)
{
    printf("Enter value: ");
    int num;
    scanf("%d",&num);

    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = num;
    newnode->next = NULL;

    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

void display(node *head)
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void reverse(node **start, node **end)
{
    node *pointer = *start;
    node *first=NULL;
    node *second=NULL;
    
    while(pointer != NULL)
    {
        second=first;
        first=pointer;
        pointer = pointer->next;
        first->next = second;
    }
    temp = *start;
    *start = first;
    printf("reverse ");
    display(*start);
    printf("\n");
    return;
}

void reverse_skip(node **head, int k) {
    int flag2=1;
    node *start = *head;
    node * back=NULL;
    node *end = *head;
    while(end != NULL ){
        for(int i=1 ; i<k ; i++)
        {
            if(end->next!=NULL){
                end = end->next;
            }
            else{
                break;
            }
        }
        node *front=NULL;
        if(end !=NULL && end->next != NULL){
            front = end->next; 
        }
        
        if(end!=NULL){
            end->next = NULL;
        }
        reverse(&start, &end);
        if(back==NULL)
        {
            *head=start;
        }
        else{
            back->next=end;
        }
        temp->next = front;
        start=front;
        end=front;
        if(end==NULL)
        {
            break;
        }
        for(int i=1 ; i<k ; i++)
        {
            if(end==NULL){
                break;
            }
            end = end->next;
        }
        back = end;
        if(back==NULL){
            break;
        }
        front=end->next;
        start= front;
        end=front;
        if(end==NULL){
            break;
        }
    }

}

int main()
{
    printf("Enter value of k : ");
    int k;
    scanf("%d",&k);
    node *head = NULL;
    node *tail = NULL;

    while(1)
    {
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            add_linked_list(&head, &tail);
            break;

            case 2:
            display(head);
            break;

            case 3:
            reverse_skip(&head,k);
            break;

            default:
            return 0;
        }

    }
    return 0;
}