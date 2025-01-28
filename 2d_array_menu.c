#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define string_size 10

void string_copy(char *str1, char *str2)
{
    int i=0;
    int j=0;
    while(str2[i] != '\0')
    {
        str1[j] = str2[i];
        j++;
        i++;
    }
    str1[j] = '\0';
}

void swap(char *str1, char *str2)
{
    char temp[string_size];
    string_copy(temp, str1);
    string_copy(str1,str2);
    string_copy(str2,temp);
}

void matrix_level_rotation(char***matrix, int r, int c)
{
    //array of strings
    char **temp_array = (char**)malloc(r*c*sizeof(char*));
    for(int i=0 ; i<r*c ; i++)
    {
        temp_array[i] = (char*)malloc(string_size*sizeof(char));
    }
    int temp_idx=0;
    for(int i=0 ; i<r ; i++)
    {
        for(int j=0 ; j<c ; j++)
        {
            temp_array[temp_idx] = matrix[i][j];
            temp_idx++;
        }
    }
    temp_idx=0;
    
    for(int j=c-1 ; j>=0 ; j--)
    {
        for(int i=0 ; i<r ; i++)
        {
            matrix[i][j] = temp_array[temp_idx];
            temp_idx++;
        }
    }
}

void left_row_rotation(char***matrix, int r, int c)
{
    int steps;
    printf("\nEnter the number of steps to rotate to left\n");
    {
        scanf("%d",&steps);
    }
    steps = steps%r;
    
    for(int i=0 ; i<r ; i++)
    {
        int ptr1 = 0;
        int ptr2 = steps-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr1++;
            ptr2--;
        }
        ptr1 = steps;
        ptr2 = c-1;
        while(ptr1 <= ptr2)
        {
        swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr1++;
            ptr2--;
        }
    }
    for(int i=0 ; i<r ; i++)
    {
        int ptr1=0;
        int ptr2=c-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr1++;
            ptr2--;
        }
    }
}

void right_row_rotation(char ***matrix, int r, int c)
{
    int steps;
    printf("\nEnter the number of steps to rotate to right\n");
    {
        scanf("%d",&steps);
    }
    steps = steps%r;
    for(int i=r-1 ; i>=0 ; i--)
    {
        int ptr1 = c-1;
        int ptr2 = c-steps;
        while(ptr2 <= ptr1)
        {
            swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr2++;
            ptr1--;
        }
        
        ptr1 = c-steps-1;
        ptr2 = 0;
        while(ptr2 <= ptr1)
        {
            swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr2++;
            ptr1--;
        }
    }
    for(int i=0 ; i<r ; i++)
    {
        int ptr1 = 0;
        int ptr2 = c-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[i][ptr1], matrix[i][ptr2]);
            ptr1++;
            ptr2--;
        }
    }
}

void up_column_rotation(char ***matrix, int r, int c)
{
    int steps;
    printf("\nEnter the number of steps to rotate to up\n");
    scanf("%d",&steps);
    steps = steps%c;
    for(int j=0 ; j<c ; j++)
    {
        int ptr1 = 0;
        int ptr2 = steps-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[ptr1][j], matrix[ptr2][j]);
            ptr1++;
            ptr2--;
        }
        ptr1 = steps;
        ptr2 = r-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[ptr1][j], matrix[ptr2][j]);
            ptr1++;
            ptr2--;
        }
    }
    for(int j=0 ; j<c ; j++)
    {
        int ptr1 = 0;
        int ptr2 = r-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[ptr1][j], matrix[ptr2][j]);
            ptr1++;
            ptr2--;
        }
    }
}

void down_column_rotation(char ***matrix, int r, int c)
{
    int steps;
    printf("\nEnter the number of steps to rotate to down\n");
    scanf("%d",&steps);
    steps = steps%c;
    for(int j=0 ; j<c ; j++)
    {
        int ptr1 = r-1;
        int ptr2 = r-steps;
        while(ptr2 <= ptr1)
        {
            swap(matrix[ptr2][j], matrix[ptr1][j]);
            ptr2++;
            ptr1--;
        }
        ptr1 = r-steps-1;
        ptr2=0;
        while(ptr2 <= ptr1)
        {
            swap(matrix[ptr2][j], matrix[ptr1][j]);
            ptr2++;
            ptr1--;
        }
    }
    for(int j=0 ; j<c ; j++)
    {
        int ptr1=0;
        int ptr2=r-1;
        while(ptr1 <= ptr2)
        {
            swap(matrix[ptr1][j], matrix[ptr2][j]);
            {
                ptr1++;
                ptr2--;
            }
        }
    }
}

int operations_menu(char***matrix, int rows, int cols)
{
    printf("\nChoose an option from below\n");
    printf("1. Matrix-Level Rotation\n");
    printf("2. Row-Wise Rotation (Left)\n");
    printf("3. Row-Wise Rotation (Right)\n");
    printf("4. Column-Wise Rotation (Up)\n");
    printf("5. Column-Wise Rotation (Down)\n");
    
    int choice;
    scanf("%d",&choice);
    
    switch(choice)
    { 
        case 1:
            matrix_level_rotation(matrix, rows, cols);
            printf("After Matrix-Level Rotation\n");
            break;
        
        case 2:
            left_row_rotation(matrix, rows, cols);
            printf("After Row-Wise Rotation (Left)\n");
            break;
        
        case 3:
            right_row_rotation(matrix, rows, cols);
            printf("After Row-Wise Rotation (Right)\n");
            break;
        
        case 4:
            up_column_rotation(matrix, rows, cols);
            printf("After Column-Wise Rotation (Up)\n");
            break;
        
        case 5:
            down_column_rotation(matrix, rows, cols);
            printf("After Column-Wise Rotation (Down)\n");
            break;
            
        case 6:
            printf("Exiting!\n");
            return 0;
        
        default:
            printf("Invalid input\n");
            break;
    }
    return 1;
}

int main()
{
    int rows;
    int cols;
    printf("Enter the size of nXn matrix\n");
    scanf("%d",&rows);
    cols=rows;
    
    //2D array of strings OR 3D array (declaration)
    char ***matrix = (char***)malloc(rows*sizeof(char**));
    for(int i=0 ; i<rows ; i++)
    {
        matrix[i] = (char**)malloc(cols*sizeof(char*));
        
        for(int j=0 ; j<cols ; j++)
        {
            matrix[i][j] = (char*)malloc(string_size*sizeof(char));
        }
    }
    
    //Taking input in 3D array
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            printf("Enter element at (%d,%d)\n",i,j);
            scanf("%s",matrix[i][j]);
        }
    }
    int v;
    do
    {
        v = operations_menu(matrix, rows, cols);
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols ; j++)
            {
                printf("%s ",matrix[i][j]);
            }
            printf("\n");
        }
    }
    while(v <= 5 && v != 0);
    
    return 0;
}
