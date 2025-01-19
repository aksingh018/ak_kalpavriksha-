#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

node *head = NULL;

void read()
{
    if(head == NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->num);
            temp = temp->next;
        }
    }
}

void insert_at_begining(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->num = value;
    newnode->next = head;
    head = newnode;
}

void insert_at_end(int value)
{
    node *newnode = head;
    node *previous = head;
    if(head == NULL)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->num = value;
        newnode->next = NULL;  
        head = newnode; 
    }
    else
    {
        while(newnode != NULL)
        {
            previous = newnode;
            newnode = newnode->next;
        }
        newnode = (node *)malloc(sizeof(node));
        newnode->num = value;
        newnode->next = NULL;
        previous->next = newnode;
    }
}

void insert_at_position(int value, int index)
{
    node *newnode = head;
    node *previous = head;
    if(head == NULL)
    {
        if(index == 1)
        {
            insert_at_begining(value);
        }
        else
        {
            printf("Invalid\n");
            return;
        }
    }
    else
    {
        if(index == 1)
        {
            newnode = (node *)malloc(sizeof(node));
            newnode->num = value;
            newnode->next = head;
            head = newnode;
        }
        else
        {
            for(int i=1 ; i<index ; i++)
            {
                previous = newnode;
                newnode = newnode->next;
                if(newnode == NULL && i < index-1)
                {
                    printf("Invalid position\n");
                    return;
                }
            }
            newnode = (node *)malloc(sizeof(node));
            newnode->num = value;
            if(newnode == NULL)
            {
                previous->next = newnode;
                newnode->next = NULL;
            }
            else
            {
                newnode->next = previous->next;
                previous->next = newnode;
            }
        }
    }  
}

void update_at_position(int position, int value)
{
    node *current_node = head;
    if(head == NULL)
    {
        printf("Invalid\n");
        return ;
    }
    else
    {
        for(int i=1 ; i<position ; i++)
        {
            if(current_node == NULL)
            {
                printf("Invalid, can't update the position dosen't exists\n");
                return;
            }
            current_node = current_node->next;
        }
        if(current_node == NULL)
        {
            printf("Invalid, can't update the position dosen't exists\n");
            return;
        }
        current_node->num = value;
    }
}

void delete_at_begining()
{
    if(head == NULL)
    {
        printf("Invalid, linked list is already empty\n");
    }
    else
    {
        head = head->next;
    }
}

void delete_at_end()
{
    node *temporary_pointer = head;
    node *previous;
    if(head == NULL)
    {
        printf("Invalid, already empty\n");
        return;
    }
    if(head->next == NULL)
    {
        head = NULL;
        return;
    }
    while(temporary_pointer->next != NULL)
    {
        previous = temporary_pointer;
        temporary_pointer = temporary_pointer->next;
    }
    previous->next = NULL;
}

void delete_at_position(int position)
{
    node *temporary_pointer = head;
    if(head == NULL)
    {
        printf("Invalid, linked list is already empty\n");
        return ;
    }
    else
    {
        if(head->next == NULL)
        {
            if(position == 1)
            {
                head = NULL;
            }
            else
            {
                printf("Invalid position");
                return ;
            }
        }
        else
        {
            if(position == 1)
            {
                head = head->next;
            }
            else if(position == 2)
            {
                head->next = head->next->next;
            }
            else
            {
                for(int i=1 ; i<position-1 ; i++)
                {
                    if(temporary_pointer == NULL)
                    {
                        printf("Invalid, can't delete here\n");
                        return;
                    }
                    temporary_pointer = temporary_pointer->next;
                }
                if(temporary_pointer->next == NULL)
                {
                    printf("Invalid!, can delete at this position\n");
                    return;
                }
                else
                {
                    temporary_pointer->next = temporary_pointer->next->next;
                }
            }
        }
    }
}

int currect_input()
{
    int input;
    printf("Enter value\n");
    scanf("%d",&input);
    if(input < -1000 || input > 1000)
    {
        printf("Integer value should be in between -1000 to 1000 ");
        currect_input();
    }
    else
    {
        return input;
    }
}


int main()
{
    int number_of_operations;
    printf("Enter number of operations : ");
    scanf("%d",&number_of_operations);

    if((number_of_operations<1 || number_of_operations >100) && !(number_of_operations >= '0' && number_of_operations <= '9'))
    {
        printf("Enter number_of_operations in the range 1 to 100\n");
        return 0;
    }
    int position;
    int value;

    while(number_of_operations)
    {
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                value=currect_input();
                insert_at_end(value);
                break;

            case 2:
                value=currect_input();
                insert_at_begining(value);
                break;

            case 3:
                value=currect_input();
                printf("Enter position\n");
                scanf("%d",&position);
                insert_at_position(value, position);
                break;

            case 4:
                read();
                break;

            case 5:
                value=currect_input();
                printf("Enter position\n");
                scanf("%d",&position);
                update_at_position(position, value);
                break;

            case 6:
                delete_at_begining();
                break;

            case 7:
                delete_at_end();
                break;

            case 8:
                printf("Enter positoin\n");
                scanf("%d",&position);
                delete_at_position(position);
                break;

            default :
                printf("Invalid choice");
                return 0;
        }
        number_of_operations--;
    }
    return 0;
}