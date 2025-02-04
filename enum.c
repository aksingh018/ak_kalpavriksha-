#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum 
{
    VIP=0,
    SENIOR_CITIZEN=1,
    GENERAL=2
}priority;

typedef struct node
{
    int passanger_id;
    char *passanger_name;
    priority passanger_type;
}node;

int isEmpty(node *queue, int front, int rear)
{
    if(front == -1)
    {
        return 1;
    }
    return 0;
}

void merge(node *queue, int start, int end, int middle)
{
    int length1 = middle-start+1;
    int length2 = end-middle;

    node *first_array = (node *)malloc(length1*sizeof(node));
    int first_iterator=0;

    node *second_array = (node *)malloc(length2*sizeof(node));
    int second_iterator=0;

    int index = start;
    for(int i=0 ; i<length1 ; i++)
    {
        first_array[i] = queue[index++];
    }
    index = middle+1;
    for(int i=0 ; i<length2 ; i++)
    {
        second_array[i] = queue[index++];
    }
    index = start;
    while(first_iterator < length1 && second_iterator < length2)
    {
        if(first_array[first_iterator].passanger_type < second_array[second_iterator].passanger_type)
        {
            queue[index++] = first_array[first_iterator++];
        }
        else
        {
            queue[index++] = second_array[second_iterator++];
        }
    }
    while(first_iterator < length1)
    {
        queue[index++] = first_array[first_iterator++];
    }
    while(second_iterator < length2)
    {
        queue[index++] = second_array[second_iterator++];
    }
}

void merge_sort(node* queue, int start, int end){
    if(start>=end){
        return;
    }

    int middle = start + (end-start)/2;
    merge_sort(queue, start, middle);
    merge_sort(queue,middle+1,end);

    merge(queue, start, end, middle);

}

void enqueue(node *queue, int *front, int *rear, int id, priority category, char *name)
{
    if(*rear == -1)
    {
        *front = 0;
    }
    *rear = (*rear) + 1;
    queue[*rear].passanger_id = id;
    queue[*rear].passanger_name = (char *)malloc(50*sizeof(char));
    strcpy(queue[*rear].passanger_name, name);
    queue[*rear].passanger_type = category;

    merge_sort(queue, *front, *rear);
}

void dequeue(node *queue, int *front, int *rear)
{
    printf("serving passanger:");
    printf("ID %d",queue[*front].passanger_id);
    printf(",Name: %s",queue[*front].passanger_name);
    if(queue[*front].passanger_type == 0)
    {
        printf(", Type: VIP");
    }
    if(queue[*front].passanger_type == 1)
    {
        printf(", Type: SENIOR_CITIZEN");
    }
    if(queue[*front].passanger_type == 2)
    {
        printf(", Type: GENERAL");
    }
    printf("\n");
    printf("\n");

    *front = (*front)+1;
}

void display(node *queue, int *rear, int *front)
{
    int temp_rear = *rear;
    int temp_front = *front;

    while(temp_front <= temp_rear)
    {
        printf("ID %d",queue[temp_front].passanger_id);
        printf(",Name: %s",queue[temp_front].passanger_name);
        if(queue[temp_front].passanger_type == 0)
        {
            printf(", Type: VIP");
        }
        if(queue[temp_front].passanger_type == 1)
        {
            printf(", Type: SENIOR_CITIZEN");
        }
        if(queue[temp_front].passanger_type == 2)
        {
            printf(", Type: GENERAL");
        }
        printf("\n");

        temp_front++;
    }
}

priority getCategory(char *type)
{
    if(strcmp(type,"GENERAL")==0)
        return GENERAL;
    else if(strcmp(type,"VIP")==0)
        return VIP;
    else 
        return SENIOR_CITIZEN;
}

int main()
{
    int number_of_operations;
    scanf("%d",&number_of_operations);

    node *queue = (node *)malloc(number_of_operations*sizeof(node));
    int front = -1;
    int rear = -1;

    int id;
    char *name = (char *)malloc(50*sizeof(char));
    char *type = (char *)malloc(30*sizeof(char));

    while(number_of_operations--)
    {
        int choice;
        scanf("%d",&choice);
        getchar();

        switch (choice)
        {
            case 1:
            scanf("%d,%[^,],\"%[^\"]\";", &id, type, name);
            priority category=getCategory(type);
            enqueue(queue, &front, &rear, id, category, name);
            break;

            case 2:
            dequeue(queue, &front, &rear);
            break;

            case 3:
            display(queue, &rear, &front);
            break;
        }
    }
}