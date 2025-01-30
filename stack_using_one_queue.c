#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUE
{
    int size;
    int front;
    int rear;
    int *array;
}queue;

int is_empty(queue *temp_pointer)
{
    if(temp_pointer->front == -1 || temp_pointer->front > temp_pointer->rear)
    {
        return 1;
    }
    return 0;
}

int is_full(queue *temp_pointer)
{
    if(temp_pointer->rear == temp_pointer->size-1)
    {
        return 1;
    }
    return 0;
}

int dequeue(queue *temp_pointer)
{
    if(is_empty(temp_pointer) == 1)
    {
        printf("Stack id empty\n");
        return -1;
    }
    else
    {
        int deleted_value = temp_pointer->array[temp_pointer->front];
        temp_pointer->front++;
        return deleted_value;
    }
}

void enqueue(queue *temp_pointer, int value)
{
    if(is_full(temp_pointer) == 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        if(temp_pointer->front == -1)
        {
            temp_pointer->front = 0;
        }
        temp_pointer->rear++;
        temp_pointer->array[temp_pointer->rear] = value;
    }
}

void push(queue *temp_pointer, int value)
{
    enqueue(temp_pointer,value);
    int number_of_iterations = temp_pointer->rear - temp_pointer->front ;
    for(int i=0 ; i<number_of_iterations ; i++)
    {
        int x = dequeue(temp_pointer);
        enqueue(temp_pointer, x);
    }
}

void pop(queue *temp_pointer)
{
    dequeue(temp_pointer);
}

void peek(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("topmost element is : %d\n",temp_pointer->array[temp_pointer->front]);
}

void size(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Size is zero\n");
    }
    else
    {
        printf("There are %d elements in the stack\n",temp_pointer->rear - temp_pointer->front +1);
    }
}

void display_stack(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Stack is empty\n");
    }
    else
    {
        int start = temp_pointer->front;
        while(start <= temp_pointer->rear)
        {
            printf("%d\n",temp_pointer->array[start]);
            start++;
        }
    }
}

int main()
{
    queue *queue_pointer = (queue *)malloc(sizeof(queue));
    printf("Enter size of queue\n");
    scanf("%d",&queue_pointer->size);
    queue_pointer->front = -1;
    queue_pointer->rear = -1;
    queue_pointer->array = (int *)malloc(queue_pointer->size*sizeof(int));

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
            push(queue_pointer,value);
            break;

            case 2:
            pop(queue_pointer);
            break;

            case 3:
            peek(queue_pointer);
            break;

            case 4:
            if(is_empty(queue_pointer))
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

            case 5:
            size(queue_pointer);
            break;

            case 6:
            display_stack(queue_pointer);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}