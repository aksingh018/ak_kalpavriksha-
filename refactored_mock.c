#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct node 
{
    int patient_id;
    int severity;
    struct node *next;
} node;
 
typedef struct map 
{
    int id;
} map;
 
void display(node *start) 
{
    while (start != NULL) 
    {
        char *severity_str;
        if (start->severity == 0) 
        {
            severity_str = "critical";
        } 
        else if (start->severity == 1) 
        {
            severity_str = "serious";
        } 
        else 
        {
            severity_str = "stable";
        }
        printf("%d:%s -> ", start->patient_id, severity_str);
        start = start->next;
    }
}
 
void addll(node **head, node **tail, int pid, int sev) 
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->patient_id = pid;
    newnode->severity = sev;
    newnode->next = NULL;
    if (*head == NULL) 
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
 
int is_unique_id(map *data, int id, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        if (data[i].id == id) 
        {
            return 0;
        }
    }
    return 1; 
}
 
int get_severity() 
{
    char severity[100];
    while (1) 
    {
        printf("Enter patient severity (critical/serious/stable): ");
        scanf("%s", severity);
 
        if (strcmp(severity, "critical") == 0) 
        {
            return 0;
        } 
        else if (strcmp(severity, "serious") == 0) 
        {
            return 1;
        } 
        else if (strcmp(severity, "stable") == 0) 
        {
            return 2;
        } 
        else 
        {
            printf("Invalid severity. Please enter again.\n");
        }
    }
}
 
int main() 
{
    node *head = NULL;
    node *tail = NULL;
 
    printf("Enter number of patients: ");
    int n;
    scanf("%d", &n);
 
    map *data = (map *)malloc(n * sizeof(map));
    int k = 0;
 
    for (int i = 1; i <= n; i++) {
        int pid, sev;
 
        while (1) 
        {
            printf("Enter patient ID for patient %d: ", i);
            scanf("%d", &pid);
 
            if (is_unique_id(data, pid, k)) 
            {
                data[k++].id = pid;
                break;
            } 
            else 
            {
                printf("Patient ID already exists. Please enter a unique ID.\n");
            }
        }
 
        sev = get_severity();
        addll(&head, &tail, pid, sev);
    }
 
    sort(&head);
    display(head);
    return 0;
}