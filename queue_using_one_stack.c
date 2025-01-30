#include<stdio.h>
#include<stdlib.h>

typedef struct STACK
{
    int size;
    int top;
    int *array;
}stack;

int is_empty(stack *temp_pointer)
{
    if(temp_pointer->top == -1)
    {
        return 1;
    }
    return 0;
}

int is_full(stack *temp_pointer)
{
    if(temp_pointer->top == temp_pointer->size-1)
    {
        return 1;
    }
    return 0;
}

void push(stack *temp_pointer, int value)
{
    if(is_full(temp_pointer))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        temp_pointer->top++;
        temp_pointer->array[temp_pointer->top] = value;
    }
}

int pop(stack *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Already empty\n");
    }
    else
    {
        int deleted_element = temp_pointer->array[temp_pointer->top];
        temp_pointer->top--;
        return deleted_element;
    }
}

int dequeue(stack *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int top_element = pop(temp_pointer);
        if(is_empty(temp_pointer))
        {
            return top_element;
        }

        int front_element = dequeue(temp_pointer);
        push(temp_pointer, top_element);

        return front_element;
    }
}

void enqueue(stack *temp_pointer, int value)
{
    push(temp_pointer, value);
}

void peek(stack *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Queue is empty\n");
    }
    else
    {
        int top_element = temp_pointer->array[temp_pointer->top];
        temp_pointer->top--;
        if(is_empty(temp_pointer))
        {
            printf("Topmost element is %d\n",top_element);
            temp_pointer->top++;
            temp_pointer->array[temp_pointer->top];
            return ;
        }
        peek(temp_pointer);
        temp_pointer->top++;
        temp_pointer->array[temp_pointer->top] = top_element;
    }
}

void size(stack *temp_pointer)
{
    printf("There are %d elements in the queue\n",temp_pointer->top+1);
}

void display_queue(stack *temp_pointer)
{
    if (is_empty(temp_pointer))
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        int top_element = temp_pointer->array[temp_pointer->top];
        temp_pointer->top--;
        display_queue(temp_pointer);
    
        printf("%d\n", top_element);
    
        temp_pointer->top++;
        temp_pointer->array[temp_pointer->top] = top_element;
    }
}

int main()
{
    stack *stack_pointer = (stack *)malloc(sizeof(stack));
    stack_pointer->top = -1;
    printf("Enter size of queue\n");
    scanf("%d",&stack_pointer->size);
    stack_pointer->array = (int *)malloc(stack_pointer->size*sizeof(int));

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
            enqueue(stack_pointer,value);
            break;

            case 2:
            dequeue(stack_pointer);
            break;

            case 3:
            peek(stack_pointer);
            break;

            case 4:
            if(is_empty(stack_pointer))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

            case 5:
            size(stack_pointer);
            break;

            case 6:
            display_queue(stack_pointer);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}