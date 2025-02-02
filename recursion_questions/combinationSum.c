#include <stdio.h>
#include <stdlib.h>

void findCombination(int index, int target, int *candidates, int candidatesSize, int **combinations, int *combinationSizes, int *currentCombination, int currentSize, int *combinationCount) {
    if (index == candidatesSize) {
        if (target == 0) {
            combinations[*combinationCount] = (int *)malloc(currentSize * sizeof(int));
            for (int i = 0; i < currentSize; i++) {
                combinations[*combinationCount][i] = currentCombination[i];
            }
            combinationSizes[*combinationCount] = currentSize;
            (*combinationCount)++;
        }
        return;
    }

    if (candidates[index] <= target) {
        currentCombination[currentSize] = candidates[index];
        findCombination(index, target - candidates[index], candidates, candidatesSize, combinations, combinationSizes, currentCombination, currentSize + 1, combinationCount);
    }

    findCombination(index + 1, target, candidates, candidatesSize, combinations, combinationSizes, currentCombination, currentSize, combinationCount);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* combinationCount, int** combinationSizes) {
    int **combinations = (int **)malloc(1000 * sizeof(int *));
    int *sizes = (int *)malloc(1000 * sizeof(int));
    int *currentCombination = (int *)malloc(1000 * sizeof(int));
    *combinationCount = 0;

    findCombination(0, target, candidates, candidatesSize, combinations, sizes, currentCombination, 0, combinationCount);

    *combinationSizes = sizes;
    return combinations;
}

int main() {
    int candidatesSize;
    printf("Enter the number of candidates: ");
    scanf("%d", &candidatesSize);

    int *candidates = (int *)malloc(candidatesSize * sizeof(int));
    printf("Enter the candidates: ");
    for (int i = 0; i < candidatesSize; i++) {
        scanf("%d", &candidates[i]);
    }

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    int combinationCount;
    int *combinationSizes;
    int **combinations = combinationSum(candidates, candidatesSize, target, &combinationCount, &combinationSizes);

    printf("Combinations are:\n");
    for (int i = 0; i < combinationCount; i++) {
        for (int j = 0; j < combinationSizes[i]; j++) {
            printf("%d ", combinations[i][j]);
        }
        printf("\n");
    }

    return 0;
}
