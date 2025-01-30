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

void display_stack(stack *temp_pointer)
{
    int temp_top = temp_pointer->top;
    if(is_empty(temp_pointer))
    {
        printf("stack is empty\n");
    }
    while(temp_top != -1)
    {
        printf("%d\n",temp_pointer->array[temp_top]);
        temp_top--;
    }
}

int main()
{
    stack *stack_pointer = (stack *)malloc(sizeof(stack));
    printf("Enter size of the stack\n");
    scanf("%d",&stack_pointer->size);
    stack_pointer->top = -1;
    stack_pointer->array = (int *)malloc(stack_pointer->size*sizeof(int));

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
            push(stack_pointer,value);
            break;

            case 2:
            pop(stack_pointer);
            break;

            case 3:
            peek(stack_pointer);
            break;

            case 4:
            if(is_empty(stack_pointer))
            {
                printf("stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;

            case 5:
            size(stack_pointer);
            break;

            case 6:
            display_stack(stack_pointer);
            break;

            default:
            printf("Invalid\n");
            return 0;
        }
    }
    return 0;
}