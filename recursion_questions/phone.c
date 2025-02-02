#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* mappings[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char* digits, int index, char* current, char** result, int* returnSize) {
    if (digits[index] == '\0') {
        result[*returnSize] = (char*)malloc((strlen(current) + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = mappings[digit];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(1000 * sizeof(char*));
    char* current = (char*)malloc((strlen(digits) + 1) * sizeof(char));
    current[strlen(digits)] = '\0';
    *returnSize = 0;

    backtrack(digits, 0, current, result, returnSize);

    return result;
}

int main() {
    char digits[100];
    printf("Enter digits (2-9): ");
    scanf("%s", digits);

    int returnSize;
    char** combinations = letterCombinations(digits, &returnSize);

    printf("Letter combinations:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", combinations[i]);
    }

    return 0;
}
