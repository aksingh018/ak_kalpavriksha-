#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void second_largest(char *string_pointer)
{
    char current_word[100];
    char largest[100];
    char sec_largest[100];
    int current_length=0;
    int maximum_length=0;
    int second_maximum_length=0;

    int index_1=0;
    int index_2=0;
    while(string_pointer[index_1] != '\0')
    {
        if(string_pointer[index_1] != ' ' && string_pointer[index_1] != '\0')
        {
            current_word[index_2] = string_pointer[index_1];
            index_2++;
        }
        else
        {
            current_word[index_2] = '\0';
            current_length = index_2;
            index_2=0;

            if(current_length > maximum_length)
            {
                for(int k=0 ; k<maximum_length ; k++)
                {
                    sec_largest[k] = largest[k];
                }
                sec_largest[maximum_length] = '\0';
                second_maximum_length = maximum_length;

                for(int k=0 ; k< current_length ; k++)
                {
                    largest[k] = current_word[k];
                }
                largest[current_length] = '\0';
                maximum_length = current_length;
            }
            else if(current_length > second_maximum_length && current_length < maximum_length)
            {
                for(int k=0 ; k<current_length ; k++)
                {
                    sec_largest[k] = current_word[k];
                }
                sec_largest[current_length] = '\0';
                second_maximum_length = current_length;
            }
        }
        index_1++;
    }
    if(index_2 > 0)
    {
        current_word[index_2] = '\0';
        current_length = index_2;

        if(current_length > maximum_length)
        {
            for(int k=0 ; k<maximum_length ; k++)
            {
                sec_largest[k] = largest[k];
            }
            sec_largest[maximum_length] = '\0';
            second_maximum_length = maximum_length;

            for(int k=0 ; k< current_length ; k++)
            {
                largest[k] = current_word[k];
            }
            largest[current_length] = '\0';
            maximum_length = current_length;
        }
        else if(current_length > second_maximum_length && current_length < maximum_length)
        {
            for(int k=0 ; k<current_length ; k++)
            {
                sec_largest[k] = current_word[k];
            }
            sec_largest[current_length] = '\0';
            second_maximum_length = current_length;
        }
    }
    if (second_maximum_length > 0)
    {
        printf("Second largest word (only considering first occurance) : ");
        for (int k = 0; k < second_maximum_length; k++)
        {
            printf("%c", sec_largest[k]);
        }
        printf("\n");
    }
    else
    {
        printf("No second largest word found.\n");
    }
}
int main()
{
    char sentence[100];
    printf("Enter a sentence \n");
    scanf("%[^\n]s",sentence);
    second_largest(sentence);
    return 0;
}