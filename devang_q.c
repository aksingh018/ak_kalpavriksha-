#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int permutation(char **list, char *array, int n, int idx, int *itr)
{
    if(idx >= n)
    {
        list[*itr] = (char *)malloc((n+1)*sizeof(char));
        strcpy(list[*itr], array);
        (*itr)++;
        return *itr;
    }
    for(int i=idx ; i<n ; i++)
    {
        swap(&array[idx], &array[i]);
        permutation(list, array, n, idx+1,itr);
        swap(&array[idx], &array[i]);
    }
    return *itr;
}

int main()
{
    char *input_word = (char *)malloc(5*sizeof(char));
    scanf("%s",input_word);
    
    int size=0;
    while(input_word[size] != '\0')
    {
        size++;
    }

    char **list = (char **)malloc(50*sizeof(char*));
    int itr=0;
    int v = permutation(list, input_word, size, 0, &itr);
    
    printf("All permutations\n");
    for(int i=0 ; i<v ; i++)
    {
        printf("%s\n", list[i]);
    }
    return 0;
}