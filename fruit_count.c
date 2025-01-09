#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int count;
} element;

int string_compare(char *source, char *destination) {
    int source_itr = 0;
    int destination_itr = 0;

    while (source[source_itr] != '\0' && destination[destination_itr] != '\0') {
        if (source[source_itr] != destination[destination_itr]) {
            return 0;
        }
        source_itr++;
        destination_itr++;
    }

    return (source[source_itr] == '\0' && destination[destination_itr] == '\0');
}

void string_copy(char *source, char *destination) {
    int source_itr = 0;
    int destination_itr = 0;

    while (source[source_itr] != '\0') {
        destination[destination_itr] = source[source_itr];
        source_itr++;
        destination_itr++;
    }
    destination[destination_itr] = '\0';
}

int is_present(char *string, element current_word[], int current_word_count) {
    for (int i = 0; i < current_word_count; i++) {
        if (string_compare(string, current_word[i].name)) {
            current_word[i].count++;
            return 1;
        }
    }
    return 0;
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    char word[10][10][100];
    element current_word[100];
    int current_word_count = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%s", word[i][j]);
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!is_present(word[i][j], current_word, current_word_count)) {
                string_copy(word[i][j], current_word[current_word_count].name);
                current_word[current_word_count].count = 1;
                current_word_count++;
            }
        }
    }

    int duplicate_found = 0;
    for (int i = 0; i < current_word_count; i++) {
        if (current_word[i].count > 1) {
            printf("%s - %d\n", current_word[i].name, current_word[i].count);
            duplicate_found = 1;
        }
    }

    if (!duplicate_found) {
        printf("No duplicates found\n");
    }

    return 0;
}

