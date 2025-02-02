#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool subsetSum(int* array, int n, int k) {
    if (k == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }

    if (array[n - 1] > k) {
        return subsetSum(array, n - 1, k);
    }

    return subsetSum(array, n - 1, k) || subsetSum(array, n - 1, k - array[n - 1]);
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int* array = (int*)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the target sum K: ");
    scanf("%d", &k);

    if (subsetSum(array, n, k)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}
