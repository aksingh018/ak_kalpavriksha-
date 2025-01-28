#include<stdio.h>
#include<stdlib.h>

void swap(int *first_number, int *second_number)
{
    int temp = *first_number;
    *first_number = *second_number;
    *second_number = temp;
}

void bubble_sort(int *array, int size)
{
    for(int i=0 ; i<size-1 ; i++)
    {
        for(int j=0 ; j<size-i-1 ; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
            }
        }
    }
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
    printf("Array before sorting \n");
    for(int i=0 ; i<array_iterator ; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    bubble_sort(array, array_iterator);
    printf("Array after sorting \n");
    for(int i=0 ; i<array_iterator ; i++)
    {
        printf("%d ",array[i]);
    }

    return 0;
}