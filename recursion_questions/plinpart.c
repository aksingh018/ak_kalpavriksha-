#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void partitionHelper(int index, char* s, int len, char** path, int pathSize, char**** res, int* resSize, int* resCapacity) {
    if (index == len) {
        if (*resSize == *resCapacity) {
            *resCapacity *= 2;
            *res = realloc(*res, *resCapacity * sizeof(char**));
        }

        (*res)[*resSize] = malloc(pathSize * sizeof(char*));
        for (int i = 0; i < pathSize; i++) {
            (*res)[*resSize][i] = strdup(path[i]);
        }
        (*resSize)++;
        return;
    }

    for (int i = index; i < len; i++) {
        if (isPalindrome(s, index, i)) {
            char* substring = malloc((i - index + 2) * sizeof(char));
            strncpy(substring, s + index, i - index + 1);
            substring[i - index + 1] = '\0';
            path[pathSize] = substring;
            partitionHelper(i + 1, s, len, path, pathSize + 1, res, resSize, resCapacity);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int len = strlen(s);
    int resCapacity = 10;
    char*** res = malloc(resCapacity * sizeof(char**));
    *returnSize = 0;

    char** path = malloc(len * sizeof(char*));
    partitionHelper(0, s, len, path, 0, &res, returnSize, &resCapacity);

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 0;
        for (int j = 0; res[i][j] != NULL; j++) {
            (*returnColumnSizes)[i]++;
        }
    }

    return res;
}

int main() {
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);

    int returnSize;
    int* returnColumnSizes;
    char*** ans = partition(s, &returnSize, &returnColumnSizes);

    printf("The Palindromic partitions are :-\n");
    printf("[ ");
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", ans[i][j]);
        }
        printf("] ");
    }
    printf("]\n");

    return 0;
}
