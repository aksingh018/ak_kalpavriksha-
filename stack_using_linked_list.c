#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

void push(node **top, int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->number = value;
    if(*top == NULL)
    {
        newnode->next = NULL;
        *top = newnode;
    }
    else
    {
        newnode->next = *top;
        *top = newnode;
    }
}

void pop(node **top)
{
    if(*top == NULL)
    {
        printf("Stack is empty, can delete from the stack\n");
    }
    else
    {
        *top = (*top)->next;
    }
}

int is_empty(node **top)
{
    if(*top == NULL)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    else
    {
        printf("Stack is not Empty\n");
        return 0;
    }
}

void peek(node *top)
{
    if(is_empty(&top) == 1)
    {
        return;
    }
    else
    {
        printf("topmost element : %d\n",top->number);
    }
}

void size(node *start)
{
    int count=0;
    if(start == NULL)
    {
        printf("size is zero\n");
    }
    else
    {
        while(start != NULL)
        {
            count++;
            start = start->next;
        }
        printf("size = %d\n",count);
    }
}

void display_stack(node *start)
{
    if(start == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while(start != NULL)
        {
            printf("%d\n",start->number);
            start = start->next;
        }
    }
}
int main()
{
    node *top = NULL;
    node *tail = NULL;

    while(1)
    {
        printf("Operations Menue\n");
        printf("1) push: Add an element to the stack.\n");
        printf("2) pop: Remove the top element from the stack.\n");
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
            push(&top,value);
            break;

            case 2:
            pop(&top);
            break;

            case 3:
            peek(top);
            break;

            case 4:
            is_empty(&top);
            break;

            case 5:
            size(top);
            break;

            case 6:
            display_stack(top);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}