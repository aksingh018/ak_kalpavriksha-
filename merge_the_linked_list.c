#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

int count_of_nodes(node *start)
{
    int length=0;
    while(start != NULL)
    {
        length++;
        start = start->next;
    }
    return length;
}

void display_linked_list(node *start)
{
    while(start != NULL)
    {
        printf("%d->",start->value);
        start = start->next;
    }
}

void add_element(node **head, node **tail, int input)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->value = input;
    newnode->next = NULL;
    if(*head == NULL)
    {
        *head = newnode;
        *tail = newnode;
    }
    else
    {
        (*tail)->next = newnode;
        *tail = newnode;
    }
}

node *find_middle(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *merge(node *list_one, node *list_two)
{
    node *dummynode = (node *)malloc(sizeof(node));
    dummynode->value = -1;
    dummynode->next = NULL;
    node *temp = dummynode;

    while(list_one != NULL && list_two != NULL)
    {
        if(list_one->value < list_two->value)
        {
            temp->next = list_one;
            temp = list_one;
            list_one = list_one->next;
        }
        else
        {
            temp->next = list_two;
            temp = list_two;
            list_two = list_two->next;
        }
    }
    if(list_one != NULL)
    {
        temp->next = list_one;
    }
    if(list_two != NULL)
    {
        temp->next = list_two;
    }
    return dummynode->next;
}

void merge_sort(node **head)
{
    if(*head==NULL || (*head)->next==NULL)
        return;
    node *lefthead = *head;
    node *middle = find_middle(*head);
    node *righthead = middle->next;
    middle->next = NULL;
    merge_sort(&lefthead);
    merge_sort(&righthead);
    *head = merge(lefthead, righthead);
}

int main()
{
    node *head1 = NULL;
    node *tail1 = NULL;

    node *head2 = NULL;
    node *tail2 = NULL;

    printf("Enter first linked list\n");
    int input1;
    while(scanf("%d",&input1) == 1)
    {
        add_element(&head1, &tail1, input1);
        if(getchar() == '\n')
        {
            break;
        }
    }

    printf("Enter secoond linked list\n");
    int input2;
    while(scanf("%d",&input2) == 1)
    {
        add_element(&head2, &tail2, input2);
        if(getchar() == '\n')
        {
            break;
        }
    }

    merge_sort(&head1);
    merge_sort(&head2);
    printf("\nFinal sorted linked list\n");
    merge(head1, head2);
    display_linked_list(head1);

    node *median;
    int count = count_of_nodes(head1);
    printf("\n");
    if(count % 2 == 0)
    {
        median = find_middle(head1);
        printf("%f",(float)(median->value + median->next->value)/2);
    }
    else
    {
        median = find_middle(head1);
        printf("%f",(float)median->value);
    }
}