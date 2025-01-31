#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int patient_id;
    int severity;
    struct node *next;
}node;

void display(node *start)
{
    while(start != NULL)
    {
        printf("%d:%d -> ",start->patient_id, start->severity);
        start = start->next;
    }
}

void addll(node **head, node **tail, int pid, int sev)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->patient_id = pid;
    newnode->severity = sev;
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

void sort(node **head)
{
    node *temp = *head;

    node *zero_head = (node *)malloc(sizeof(node));
    zero_head->patient_id = -1;
    zero_head->severity = -1;
    zero_head->next = NULL;
    node *temp_zero = zero_head;

    node *one_head = (node *)malloc(sizeof(node));
    one_head->patient_id = -1;
    one_head->severity = -1;
    one_head->next = NULL;
    node *temp_one = one_head;

    node *two_head = (node *)malloc(sizeof(node));
    two_head->patient_id = -1;
    two_head->severity = -1;
    two_head->next = NULL;
    node *temp_two = two_head;

    while(temp != NULL)
    {
        printf("Entered loop\n");
        if(temp->severity == 0)
        {
            temp_zero->next = temp;
            temp_zero = temp_zero->next;
            temp = temp->next;
        }
        else if(temp->severity == 1)
        {
            temp_one->next = temp;
            temp_one = temp_one->next;
            temp = temp->next;
        }
        else
        {
            temp_two->next = temp;
            temp_two = temp_two->next;
            temp = temp->next;
        }
    }
    temp_zero->next = NULL;
    temp_one->next = NULL;
    temp_two->next = NULL;

    temp_zero->next = one_head->next;
    temp_one->next = two_head->next;
    *head = zero_head->next;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    printf("Enter number of patient : ");
    int n;
    scanf("%d",&n);

    int pid;
    int sev;
    //critical=0;
    //serious = 1;
    //stable=2;
    for(int i=1 ; i<=n ; i++)
    {
        printf("Enter %dth patient details : ",i);
        printf("Enter patient id : ");
        scanf("%d",&pid);
        printf("Enter patient situation : ");
        scanf("%s",&sev);
        addll(&head, &tail, pid, sev);
    }

    sort(&head);
    display(head);
}