#include<stdio.h>
#include<stdlib.h>

void swap(int *first_number, int *second_number)
{
    int temp = *first_number;
    *first_number = *second_number;
    *second_number = temp;
}

int partition(int *array, int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;

    while(i<j)
    {
        while(array[i] <= array[pivot] && i <= high-1)
        {
            i++;
        }

        while(array[j] >= array[pivot] && j >= low+1)
        {
            j--;
        }

        if(i<j)
        {
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[j], &array[pivot]);
    return j;
}

void quick_sort(int *array, int low, int high)
{
    if(low < high)
    {
        int pivot_index = partition(array, low, high);

        quick_sort(array, low, pivot_index-1);
        quick_sort(array, pivot_index+1, high);
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
    quick_sort(array, 0, array_iterator-1);
    printf("Array after sorting \n");
    for(int i=0 ; i<array_iterator ; i++)
    {
        printf("%d ",array[i]);
    }
}