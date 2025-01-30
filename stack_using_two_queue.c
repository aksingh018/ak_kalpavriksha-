#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUE
{
    int size;
    int front;
    int rear;
    int *array;
}queue;

int is_empty(queue *temp_queue)
{
    if(temp_queue->front == -1 || temp_queue->front > temp_queue->rear)
    {
        return 1;
    }
    return 0;
}

int is_full(queue *temp_queue)
{
    if(temp_queue->rear == temp_queue->size-1)
    {
        return 1;
    }
    return 0;
}

int dequeue(queue *temp_queue)
{
    if(is_empty(temp_queue))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        int deleted_element = temp_queue->array[temp_queue->front];
        temp_queue->front++;
        return deleted_element;
    }
}

void enqueue(queue *temp_queue, int value)
{
    if(is_full(temp_queue))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        if(temp_queue->front == -1)
        {
            temp_queue->front = 0;
        }
        temp_queue->rear++;
        temp_queue->array[temp_queue->rear] = value;
    }
}

void push(queue *first_queue, queue *second_queue, int value)
{
    enqueue(first_queue, value);
    if (!is_empty(second_queue))
    {
        while(second_queue->front <= second_queue->rear)
        {
            int x = dequeue(second_queue);
            enqueue(first_queue, x);
        }
    }

    while(first_queue->front <= first_queue->rear)
    {
        int x = dequeue(first_queue);
        enqueue(second_queue, x);
    }
}

void pop(queue *second_queue)
{
    dequeue(second_queue);
}

void peek(queue *second_queue)
{
    if(is_empty(second_queue))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        printf("Topmost element is : %d\n",second_queue->array[second_queue->front]);
    }
}

void size(queue *second_queue)
{
    if(is_empty(second_queue))
    {
        printf("Size is zero\n");
    }
    else
    {
        printf("There are %d elements in the stack\n",second_queue->rear - second_queue->front + 1);
    }
}

void display_stack(queue *second_queue)
{
    if(is_empty(second_queue))
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        int start = second_queue->front;
        while(start <= second_queue->rear)
        {
            printf("%d\n",second_queue->array[start]);
            start++;
        }
    }
}

int main()
{
    queue *first_queue = (queue *)malloc(sizeof(queue));
    first_queue->front = -1;
    first_queue->rear = -1;
    printf("Enter size of first queue\n");
    scanf("%d",&first_queue->size);
    first_queue->array = (int *)malloc(first_queue->size*sizeof(int));

    queue *second_queue = (queue *)malloc(sizeof(queue));
    second_queue->front = -1;
    second_queue->rear = -1;
    printf("Enter size of second queue\n");
    scanf("%d",&second_queue->size);
    second_queue->array = (int *)malloc(second_queue->size*sizeof(int));

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
            push(first_queue, second_queue, value);
            break;

            case 2:
            pop(second_queue);
            break;

            case 3:
            peek(second_queue);
            break;

            case 4:
            if(is_empty(second_queue))
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

            case 5:
            size(second_queue);
            break;

            case 6:
            display_stack(second_queue);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}