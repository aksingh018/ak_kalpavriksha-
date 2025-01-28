#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sortString(char* str) {
   int len = strlen(str);
   for (int i = 0; i < len - 1; i++) {
       for (int j = i + 1; j < len; j++) {
           if (str[i] > str[j]) {
               char temp = str[i];
               str[i] = str[j];
               str[j] = temp;
           }
       }
   }
}
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
   if (strsSize == 0) {
       *returnSize = 0;
       return NULL;
   }
   char*** result = (char***)malloc(strsSize * sizeof(char**));
   *returnColumnSizes = (int*)malloc(strsSize * sizeof(int));
   int groupCount = 0;
   char** sortedStrs = (char**)malloc(strsSize * sizeof(char*));
   for (int i = 0; i < strsSize; i++) {
       sortedStrs[i] = strdup(strs[i]);
       sortString(sortedStrs[i]);
   }
   int* grouped = (int*)calloc(strsSize, sizeof(int));
   for (int i = 0; i < strsSize; i++) {
       if (grouped[i]) continue;
       result[groupCount] = (char**)malloc(strsSize * sizeof(char*));
       int count = 0;
       for (int j = i; j < strsSize; j++) {
           if (!grouped[j] && strcmp(sortedStrs[i], sortedStrs[j]) == 0) {
               result[groupCount][count++] = strs[j];
               grouped[j] = 1;
           }
       }
       (*returnColumnSizes)[groupCount] = count;
       groupCount++;
   }
   *returnSize = groupCount;
   return result;
}
int main() {
   int strsSize;
   printf("Enter the number of strings: ");
   scanf("%d", &strsSize);

   char** strs = (char**)malloc(strsSize * sizeof(char*));

   printf("Enter the strings:\n");
   for (int i = 0; i < strsSize; i++) {
       strs[i] = (char*)malloc(100 * sizeof(char));
       scanf("%s", strs[i]);
   }
   int returnSize;
   int* returnColumnSizes;

   char*** result = groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

   printf("Group count: %d\n", returnSize);
   for (int i = 0; i < returnSize; i++) {
       printf("Group %d: ", i + 1);
       for (int j = 0; j < returnColumnSizes[i]; j++) {
           printf("%s ", result[i][j]);
       }
       printf("\n");
   }
   
   return 0;
}