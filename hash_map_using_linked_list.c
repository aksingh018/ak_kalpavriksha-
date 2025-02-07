#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    int value;
    struct node *next;
}node;

int hashFuntion(int key)
{
    return key%10;
}

void insert(node *array, int index, int number)
{
    int newIndex = hashFuntion(index);
    if(array[newIndex].key == -1)
    {
        array[newIndex].key = index;
        array[newIndex].value = number;
        array[newIndex].next = NULL;
    }
    if(array[newIndex].key == index)
    {
        array[newIndex].value = number;
        return;
    }
    
    
        node *temp = array[newIndex].next;
        while(temp != NULL)
        {
            if(temp->key == index)
            {
                temp->value = number;
                return;
            }
            temp = temp->next;
        }
    
        node *newnode = (node *)malloc(sizeof(node));
        temp = &array[newIndex];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->key = index;
        newnode->value = number;
        newnode->next = NULL;
        temp->next = newnode;
}

void display(node *array)
{
    for(int i=0 ; i<10 ; i++)
    {
        if(array[i].key == -1)
        {
            printf("Empty at this index %d\n",i+1);
        }
        else
        {
            node *temp = &array[i];
            while(temp != NULL)
            {
                printf("(%d : %d) -> ",temp->key, temp->value);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

void search(node *array, int index)
{
    int newIndex = hashFuntion(index);
    if(array[newIndex].key == -1)
    {
        printf("No element at this index %d\n",newIndex);
        return;
    }
    else
    {
        node *temp = &array[newIndex];
        while(temp != NULL)
        {
            if(temp->key == index)
            {
                printf("%d\n",temp->value);
                return;
            }
            temp = temp->next;
        }
    }
    printf("No element found\n");
}

void delete(node* array, int index) {
    int newIndex = hashFuntion(index);
    node* temporary_node = &array[newIndex];
    node* previous_node = NULL;
 
    while (temporary_node != NULL) {
        if (temporary_node->key == index) {
            if (previous_node == NULL) {
                if (temporary_node->next != NULL) {
                    temporary_node->key = temporary_node->next->key;
                    temporary_node->value = temporary_node->next->value;
                    node* to_delete = temporary_node->next;
                    temporary_node->next = temporary_node->next->next;
                } else {
                    temporary_node->key = -1;
                    temporary_node->value = -1;
                    temporary_node->next = NULL;
                }
            } else {
                previous_node->next = temporary_node->next;
            }
            printf("Key %d deleted successfully\n", index);
            return ;
        }
        previous_node = temporary_node;
        temporary_node = temporary_node->next;
    }
    printf("Key not found\n");
    return ;
}

int main()
{
    node *head = NULL;
    node *tail = head;

    node *array = (node *)malloc(10*sizeof(node));

    for(int i=0 ; i<10 ; i++)
    {
        array[i].key = -1;
        array[i].value = -1;
    }

    int index;
    int number;

    while(1)
    {
        printf("Enyer choice\n");
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
            printf("Enter index\n");
            scanf("%d",&index);
            while(index < 0)
            {
                printf("Enter again\n");
                printf("Enter index\n");
                scanf("%d",&index);   
            }
            printf("Enter number\n");
            scanf("%d",&number);
            while(number < 0)
            {
                printf("Enter again\n");
                printf("Enter index\n");
                scanf("%d",&index);   
            }
            insert(array, index, number);
            break;

            case 2:
            display(array);
            break;

            case 3:
            printf("Enter index\n");
            scanf("%d",&index);
            search(array, index);
            break;

            case 4:
            printf("Enter index\n");
            scanf("%d",&index);
            delete(array, index);
            break;

            default:
            return 0;
        }
    }

}