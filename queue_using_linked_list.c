#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

void enqueue(node **rear, node **front, int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->number = value;
    if(*rear == NULL)
    {
        newnode->next = NULL;
        *rear = newnode;
        *front = newnode;
    }
    else
    {
        newnode->next = NULL;
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

void dequeue(node **rear, node **front)
{
    if(*front == NULL)
    {
        printf("Queue is already empty nothing to delete\n");
        *rear = NULL;
        return;
    }
    else
    {
        *front = (*front)->next;
    }
}

int is_empty(node *front)
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return 1;
    }
    else
    {
        printf("Queue is not Empty\n");
        return 0;
    }
}

void peek(node *front)
{
    if(is_empty(front) == 1)
    {
        return;
    }
    else
    {
        printf("topmost element is : %d\n",front->number);
    }
}

void size(node *start)
{
    int count=0;
    if(start == NULL)
    {
        printf("Size is zero\n");
    }
    else
    {
        while(start != NULL)
        {
            count++;
            start = start->next;
        }
        printf("size of the queue is : %d\n", count);
    }
}

void display_queue(node *start)
{
    if(start == NULL)
    {
        printf("Queue is empty\n");
    }
    while(start != NULL)
    {
        printf("%d\n",start->number);
        start = start->next;
    }
}

int main()
{
    node *rear = NULL;
    node *front = NULL;

    while(1)
    {
        printf("Operations Menue\n");
        printf("1) enqueue: Add an element to the queue.\n");
        printf("2) dequeue: Remove the front element from the queue.\n");
        printf("3) peek: Retrieve the top element without removing it.\n");
        printf("4) isEmpty: Check if the stack is empty.\n");
        printf("5) size: Return the number of elements in the stack.\n");
        printf("6) Display all elements in the stack\n");

        printf("Choose Option\n");
        int choice;
        scanf("%d",&choice);
        int value;

        switch(choice)
        {
            case 1:
            printf("Enter value to push in the stack\n");
            scanf("%d",&value);
            enqueue(&rear, &front,value);
            break;

            case 2:
            dequeue(&rear, &front);
            break;

            case 3:
            peek(front);
            break;

            case 4:
            is_empty(front);
            break;

            case 5:
            size(front);
            break;

            case 6:
            display_queue(front);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}