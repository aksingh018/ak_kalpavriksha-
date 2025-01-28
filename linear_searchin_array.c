#include<stdio.h>
#include<stdlib.h>

void linear_search(int *array, int size, int element)
{
    for(int i=0 ; i<size ; i++)
    {
        if(array[i] == element)
        {
            printf("Element found at %dth position\n", i+1);
            return;
        }
    }
    printf("Element doesn't exists in the array");
}

int main()
{
    printf("Enter an array : ");
    char *input_string = (char *)malloc(100*sizeof(char));
    int string_iterator=0;
    scanf("%[^\n]s",input_string);

    int *array = (int *)malloc(100*sizeof(int));
    int array_iterator=0;
    int num=0;
    while(input_string[string_iterator] != '\0')
    {
        if(input_string[string_iterator] >= '0' && input_string[string_iterator] <= '9')
        {
            num = num*10 + (input_string[string_iterator] - '0');
        }
        else if(input_string[string_iterator] == ' ')
        {
            array[array_iterator++] = num;
            num=0;
        }
        else
        {
            printf("Invalid input! only integer value and spaces are allowed\n");
            return 0;
        }
        string_iterator++;
    }
    array[array_iterator++] = num;

    printf("Enter an element to search : ");
    int element;
    scanf("%d",&element);

    linear_search(array, array_iterator, element);
    return 0;
}