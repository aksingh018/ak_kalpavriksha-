#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char character;
    int count;
} map;

int main()
{
    printf("Enter string: ");
    char *input_string = (char *)malloc(100*sizeof(char));
    scanf("%s", input_string);
    getchar();
    
    char replace_character;
    scanf("%c",&replace_character);
    
    // printf("%s",str);
    
    map *data = (map *)malloc(100*sizeof(map));
    int k=0;
    
    int i=0;
    while(input_string[i] != '\0')
    {
        int found=0;
        for(int x=0 ; x<k ; x++)
        {
            if(input_string[i] == data[x].character)
            {
                data[x].count++;
                found=1;
                break;
            }
        }
        if(!found)
        {
            data[k].character = input_string[i];
            data[k].count=1;
            k++;
        }
        i++;
    }
    
    for(int x=0 ; x<k ; x++)
    {
        if(data[x].count == 1)
        {
            data[x].character = replace_character;
            break;
        }
    }
    
    for(int x=0 ; x<k ; x++)
    {
        while(data[x].count != 0)
        {
            printf("%c",data[x].character);
            data[x].count--;
        }
    }
}