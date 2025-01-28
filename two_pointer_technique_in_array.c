#include<stdio.h>
#include<stdlib.h>

void two_pointer(int *array, int low, int high, int target)
{
    while(low <= high)
    {
        int current_sum = array[low] + array[high];
        if(current_sum == target)
        {
            printf("target sum found in the array\n");
            return;
        }
        else if(current_sum > target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    printf("target sum not found in the array");
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

    printf("Enter an target : ");
    int target;
    scanf("%d",&target);

    two_pointer(array, 0, array_iterator-1, target);
    return 0;
}