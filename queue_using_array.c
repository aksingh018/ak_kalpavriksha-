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

void enqueue(queue *temp_pointer, int value)
{
    if(is_full(temp_pointer))
    {
        printf("Queue Overflow\n");
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

int dequeue(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Queue is empty, can delete from the stack\n");
        return -1;
    }
    else
    {
        int deleted_value = temp_pointer->array[temp_pointer->front];
        temp_pointer->front++;
        return deleted_value;
    }
}


void peek(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("No elements in the queue\n");
    }
    else
    {
        printf("The top element in the stack is : %d\n",temp_pointer->array[temp_pointer->front]);
        return;
    }
}

void size(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Size is Zero\n");
    }
    else
    {
        printf("There are total %d elements is the queue\n",temp_pointer->rear - temp_pointer->front + 1);
        return;
    }
}

void display_queue(queue *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("stack is empty\n");
    }
    else
    {
        int temp_top = temp_pointer->front;
        while(temp_top <= temp_pointer->rear)
        {
            printf("%d\n",temp_pointer->array[temp_top]);
            temp_top++;
        }
    }
}

int main()
{
    queue *queue_pointer = (queue *)malloc(sizeof(queue));
    printf("Enter size of the stack\n");
    scanf("%d",&queue_pointer->size);
    queue_pointer->front = -1;
    queue_pointer->rear = -1;
    queue_pointer->array = (int *)malloc(queue_pointer->size*sizeof(int));

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
            enqueue(queue_pointer,value);
            break;

            case 2:
            dequeue(queue_pointer);
            break;

            case 3:
            peek(queue_pointer);
            break;

            case 4:
            if(is_empty(queue_pointer))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

            case 5:
            size(queue_pointer);
            break;

            case 6:
            display_queue(queue_pointer);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}