#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
   int row = 0;
   int col = *matrixColSize - 1;
   while (col >= 0 && row < matrixSize) {
       if (matrix[row][col] > target) {
           col--;
       } else if (matrix[row][col] < target) {
           row++;
       } else if (matrix[row][col] == target) {
           return true;
       }
   }
   return false;
}
int main() {
   int matrixSize, target;
   printf("Enter the number of rows: ");
   scanf("%d", &matrixSize);
   int* matrixColSize = (int*)malloc(sizeof(int));
   printf("Enter the number of columns: ");
   scanf("%d", matrixColSize);
   int** matrix = (int**)malloc(matrixSize * sizeof(int*));
   for (int i = 0; i < matrixSize; i++) {
       matrix[i] = (int*)malloc(*matrixColSize * sizeof(int));
   }

   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < matrixSize; i++) {
       for (int j = 0; j < *matrixColSize; j++) {
           printf("Enter element at position [%d][%d]: ", i, j);
           scanf("%d", &matrix[i][j]);
       }
   }

   printf("Enter the target value: ");
   scanf("%d", &target);

   if (searchMatrix(matrix, matrixSize, matrixColSize, target)) {
       printf("Target found in the matrix.\n");
   } else {
       printf("Target not found in the matrix.\n");
   }
   return 0;
}