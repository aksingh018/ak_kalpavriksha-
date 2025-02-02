#include<stdio.h>
#include<stdlib.h>

void generate(char *result, int size, int index, int open_count, int close_count)
{
    if(index == size)
    {
        for(int i=0 ; i<size ; i++)
        {
            printf("%c",result[i]);
        }
        printf("\n");
        return;
    }

    if(open_count < size/2)
    {
        result[index] = '(';
        generate(result, size, index+1, open_count+1, close_count);
    }

    if(close_count < open_count)
    {
        result[index] = ')';
        generate(result, size, index+1, open_count, close_count+1);
    }
}

int main()
{
    printf("Enter number\n");
    int n;
    scanf("%d",&n);

    char *result = (char *)malloc(2*n*sizeof(char));
    int open_count=0;
    int close_count=0;
    int index=0;
    generate(result, 2*n, index, open_count, close_count);
}