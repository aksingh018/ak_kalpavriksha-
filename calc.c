#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push_int(float *arr, int *top, float val)
{
    (*top)++;
    arr[*top] = val;
}

float pop_int(float *arr, int *top)
{
    float res = arr[*top];
    (*top)--;
    return res;
}

void push_char(char *arr, int *top, int val)
{
    (*top)++;
    arr[*top] = val;
}

char pop_char(char *arr, int *top)
{
    char res = arr[*top];
    (*top)--;
    return res;
}

int PriorityOfOperators(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }
    if(c == '*' || c == '/')
    {
        return 2;
    }
    return 0;
}

float PerformOperation(float num1, float num2, char operator)
{
    if(operator == '+')
    {
        return num1+num2;
    }
    else if(operator == '-')
    {
        return num1-num2;
    }
    else if(operator == '*')
    {
        return num1*num2;
    }
    else
    {
        if(num2==0)
        {
            printf("Error: Division by zero");
            exit(1);
        }
        return (int)(num1/num2);
    }
    return 0;
}

int main()
{
    int size = 100;
    char *exp = (char *)malloc(size * sizeof(char));
    printf("Enter Expression \n");
    scanf("%[^\n]", exp);

    float *num = (float *)malloc(size*sizeof(float));
    int num_top = -1;

    char *operator = (char *)malloc(size*sizeof(char));
    int operator_top = -1;

    for(int i=0 ; i<strlen(exp) ; i++)
    {
        // if(isspace(exp[i]))
        // {
        //     continue;
        // }
        if(exp[i] == ' ' || exp[i] == '\n' || exp[i] == '\t') 
        {
            continue;
        }
        if((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if(exp[i] >= '0' && exp[i] <= '9')
            {
                float num_value = 0;
                while(i < strlen(exp) && exp[i] >= '0' && exp[i] <= '9')
                {
                    num_value = num_value*10 + (exp[i]-'0');
                    i++;
                }
                i--;
                push_int(num, &num_top, num_value);
            }
            else
            {
                while(operator_top != -1 && PriorityOfOperators(operator[operator_top]) >= PriorityOfOperators(exp[i]))
                {
                    char x = pop_char(operator, &operator_top);
                    float b = pop_int(num, &num_top);
                    float a = pop_int(num, &num_top);
                    push_int(num, &num_top, PerformOperation(a,b,x));
                }
                push_char(operator, &operator_top, exp[i]);
            }
        }
        else
        {
            printf("Error: Invalid expression");
            return 1;
        }
    }

    while(operator_top != -1)
    {
        char x = pop_char(operator, &operator_top);
        float b = pop_int(num, &num_top);
        float a = pop_int(num, &num_top);
        push_int(num, &num_top, PerformOperation(a,b,x));
    }

    float sol = pop_int(num, &num_top);
    int result = (int)sol;
    printf("Result: %d", result);
    return 0;
}