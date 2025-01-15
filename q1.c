#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *first_number, int *second_number)
{
    int temp = *first_number;
    *first_number = *second_number;
    *second_number = temp;
}

int main()
{
    printf("Enter size : ");
    int size;
    scanf("%d",&size);
    
    int array[size][size];
    
    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            printf("Enter at %d,%d \n",i,j);
            scanf("%d", &array[i][j]);
        }
    }
    
    for(int i=0 ; i<=(size)/2 ; i++)
    {
        for(int j=i ; j<size ; j++)
        {
            swap(&array[i][j], &array[j][i]);
        }
    }
    
    for(int i=0 ; i<size ; i++)
    {
        for(int j=0 ; j<size ; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}