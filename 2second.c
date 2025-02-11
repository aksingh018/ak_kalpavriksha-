#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map {
    char c;
    int count;
} map;

int main() {
    map *data = (map *)malloc(100 * sizeof(map));
    int k = 0;

    char **array = (char **)malloc(20 * sizeof(char *));
    int index=0;
    int itr = 0;

    char *input_word = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]",input_word);
    int input_iterator=0;

    char *current_word = (char *)malloc(100*sizeof(char));
    int current_iterator=0;
    while(input_word[input_iterator] != '\0')
    {
        while(input_word[input_iterator] != ' ' && input_word[input_iterator] != '\0')
        {
            current_word[current_iterator++] = input_word[input_iterator++];
        }
        current_word[current_iterator] = '\0';
        array[index] = (char *)malloc(100*sizeof(char));
        strcpy(array[index],current_word);

        current_iterator=0;
        index++;
        input_iterator++;
    }

    for(int i=0 ; i<index ; i++)
    {
        printf("%s-",array[i]);
    }
    printf("\n");

    int maxLength = 0;

    for (int i = 0; i < index - 1; i++) {
        k = 0;
        int x = 0;
        while (array[i][x] != '\0') {
            data[k].c = array[i][x];
            data[k].count = 1;
            k++;
            x++;
        }
        for (int j = i + 1; j < index; j++) {
            int common_found = 0;
            for (x = 0; array[j][x] != '\0'; x++) {
                for (int y = 0; y < k; y++) {
                    if (data[y].c == array[j][x]) {
                        common_found = 1;
                        break;
                    }
                }
                if (common_found) {
                    break;
                }
            }
            if (!common_found) {
                int currLength = strlen(array[i]) * strlen(array[j]);
                if (maxLength < currLength) {
                    maxLength = currLength;
                }
            }
        }
    }

    printf("%d", maxLength);

    return 0;
}
