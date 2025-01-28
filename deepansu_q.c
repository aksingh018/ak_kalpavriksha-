#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* generateNextSequence(const char* input) {
   int len = strlen(input);
   char* result = (char*)malloc((2 * len + 1) * sizeof(char));
   
   int index = 0;
   for (int i = 0; i < len;) {
       char currentChar = input[i];
       int count = 0;
       while (i < len && input[i] == currentChar) {
           count++;
           i++;
       }
       index += sprintf(result + index, "%d%c", count, currentChar);
   }
   result[index] = '\0';
   return result;
}
char* countAndSay(int n) {
   if (n <= 0)
   {
        return NULL;
   }
   char* result = (char*)malloc(2 * sizeof(char));
   
   strcpy(result, "1");
   for (int i = 2; i <= n; i++) {
       char* nextSequence = generateNextSequence(result);
       result = nextSequence;
   }
   return result;
}
int main() {
   int n;
   printf("Enter the value of n: ");
   scanf("%d", &n);
   char* result = countAndSay(n);
   if (result) {
       printf("The %d-th term in the Count and Say sequence is: %s\n", n, result);
   } else {
       printf("Invalid input for n.\n");
   }
   return 0;
}