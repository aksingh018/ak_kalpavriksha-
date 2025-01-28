#include<stdio.h>
#include<stdlib.h>

void merge(int *array, int start, int end)
{
    int mid = start + (end-start)/2;
    int length1 = mid-start+1;
    int length2 = end-mid;

    int *first_array = (int *)malloc(length1*sizeof(int));
    int first_iterator = 0;

    int *second_array = (int *)malloc(length2*sizeof(int));
    int second_iterator = 0;

    int main_array_index = start;
    for(int i=0 ; i<length1 ; i++)
    {
        first_array[i] = array[main_array_index++];
    }

    main_array_index = mid+1;
    for(int i=0 ; i<length2 ; i++)
    {
        second_array[i] = array[main_array_index++];
    }

    main_array_index = start;
    while(first_iterator < length1 && second_iterator < length2)
    {
        if(first_array[first_iterator] < second_array[second_iterator])
        {
            array[main_array_index++] = first_array[first_iterator++];
        }
        else
        {
            array[main_array_index++] = second_array[second_iterator++];
        }
    }
    while(first_iterator < length1)
    {
        array[main_array_index++] = first_array[first_iterator++];
    }
    while(second_iterator < length2)
    {
        array[main_array_index++] = second_array[second_iterator++];
    }
}

void merge_sort(int *array, int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int middle = start + (end-start)/2;
    merge_sort(array, start, middle);
    merge_sort(array, middle+1, end);
    merge(array, start, end);
}

void binary_search(int *array, int low, int high, int element)
{
    while(low <= high)
    {
        int middle_index = low + (high-low)/2;
        if(array[middle_index] < element)
        {
            low = middle_index+1;
            return binary_search(array, low, high, element);
        }
        else if(array[middle_index] > element)
        {
            high = middle_index-1;
            return binary_search(array, low, high, element);
        }
        else if(array[middle_index] == element)
        {
            printf("Element found at %dth position\n",middle_index+1);
            return;
        }
    }
    printf("Element doesn't exists in the array\n");
    return;
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

    merge_sort(array, 0, array_iterator-1);
    printf("Array after sorting \n");
    for(int i=0 ; i<array_iterator ; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    binary_search(array, 0, array_iterator-1, element);
    return 0;
}