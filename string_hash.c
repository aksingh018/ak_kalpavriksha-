#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct stack {
    int top;
    char *string;
} stack;
 
void push(stack *str, char character) {
    str->top++;
    str->string[str->top] = character;
}
 
void pop(stack *str) {
    if (str->top >= 0) {
        str->top--;
    }
}
 
void processString(stack *str, char *input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '#') {
            pop(str);
        } else {
            push(str, input[i]);
        }
        i++;
    }
}
 
bool compareStacks(stack *str1, stack *str2) {
    if (str1->top != str2->top) {
        return false;
    }
    for (int i = 0; i <= str1->top; i++) {
        if (str1->string[i] != str2->string[i]) {
            return false;
        }
    }
    return true;
}
 
int main() {
    printf("Enter first string\n");
    char *first_string = (char *)malloc(200 * sizeof(char));
    scanf("%s", first_string);
 
    printf("Enter second string\n");
    char *second_string = (char *)malloc(200 * sizeof(char));
    scanf("%s", second_string);
 
    stack *stack_pointer1 = (stack *)malloc(sizeof(stack));
    stack_pointer1->top = -1;
    stack_pointer1->string = (char *)malloc(200 * sizeof(char));
 
    stack *stack_pointer2 = (stack *)malloc(sizeof(stack));
    stack_pointer2->top = -1;
    stack_pointer2->string = (char *)malloc(200 * sizeof(char));
 
    processString(stack_pointer1, first_string);
    processString(stack_pointer2, second_string);
 
    if (compareStacks(stack_pointer1, stack_pointer2)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
 
    return 0;
}