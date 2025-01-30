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
        printf("Queue is full\n");
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
        printf("Stack is empty, can delete from the stack\n");
        return -1;
    }
    else
    {
        int deleted_value = temp_pointer->array[temp_pointer->top];
        temp_pointer->top--;
        return deleted_value;
    }
}

int dequeue(stack *second_stack)
{
    pop(second_stack);
}

void enqueue(stack *first_stack, stack *second_stack, int value)
{
    push(first_stack, value);
    if(second_stack->top == -1)
    {
        while(first_stack->top != -1)
        {
            int x = pop(first_stack);
            push(second_stack, x);
        }
    }
}

void peek(stack *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("No elements in the stack\n");
    }
    else
    {
        printf("The top element in the stack is : %d\n",temp_pointer->array[temp_pointer->top]);
        return;
    }
}

void size(stack *temp_pointer)
{
    if(is_empty(temp_pointer))
    {
        printf("Size is Zero\n");
    }
    else
    {
        printf("There are total %d elements is the stack\n",temp_pointer->top+1);
        return;
    }
}

void display_queue(stack *temp_pointer)
{
    int temp_top = temp_pointer->top;
    if(is_empty(temp_pointer))
    {
        printf("stack is empty\n");
    }
    else
    {
        while(temp_top != -1)
        {
            printf("%d\n",temp_pointer->array[temp_top]);
            temp_top--;
        }
    }
}

int main()
{
    stack *first_stack = (stack *)malloc(sizeof(stack));
    first_stack->top = -1;
    printf("Enter size of queue\n");
    scanf("%d",&first_stack->size);
    first_stack->array = (int *)malloc(first_stack->size*sizeof(int));

    stack *second_stack = (stack *)malloc(sizeof(stack));
    second_stack->top = -1;
    second_stack->array = (int *)malloc(first_stack->size*sizeof(int));

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
            enqueue(first_stack, second_stack,value);
            break;

            case 2:
            dequeue(second_stack);
            break;

            case 3:
            peek(second_stack);
            break;

            case 4:
            if(is_empty(second_stack))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

            case 5:
            size(second_stack);
            break;

            case 6:
            display_queue(second_stack);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}