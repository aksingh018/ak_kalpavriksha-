#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct map
{
    char c;
    int count;
}map;

int main()
{
    map *data = (map *)malloc(100*sizeof(map));
    int k=0;

    printf("Enter a string\n");
    char *input = (char *)malloc(100*sizeof(char));
    scanf("%s",input);
    printf("Input is %s\n",input);
    int itr=0;

    while(input[itr] != '\0')
    {
        int found=0;
        for(int i=0 ; i<k ; i++)
        {
            if(data[i].c == input[itr])
            {
                data[i].count++;
                found=1;
                break;
            }
        }
        if(!found)
        {
            data[k].c = input[itr];
            data[k].count=1;
            k++;
        }

        int print_count=0;
        for(int x=0 ; x<k ; x++)
        {
            if(data[x].count == 1)
            {
                printf("%c",data[x].c);
                print_count=1;
                break;
            }
        }
        if(!print_count)
        {
            printf("-1");
        }

        itr++;
    }
}