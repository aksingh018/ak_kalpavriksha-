#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findPathHelper(int x, int y, int** grid, int size, char*** paths, int* pathCount, char* move, int** visited) {
    if (x == size - 1 && y == size - 1) {
        paths[*pathCount] = (char**)malloc(sizeof(char*));
        paths[*pathCount][0] = (char*)malloc((strlen(move) + 1) * sizeof(char));
        strcpy(paths[*pathCount][0], move);
        (*pathCount)++;
        return;
    }

    if (x + 1 < size && !visited[x + 1][y] && grid[x + 1][y] == 1) {
        visited[x][y] = 1;
        char newMove[100];
        strcpy(newMove, move);
        newMove[strlen(move)] = 'D';
        newMove[strlen(move) + 1] = '\0';
        findPathHelper(x + 1, y, grid, size, paths, pathCount, newMove, visited);
        visited[x][y] = 0;
    }

    if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == 1) {
        visited[x][y] = 1;
        char newMove[100];
        strcpy(newMove, move);
        newMove[strlen(move)] = 'L';
        newMove[strlen(move) + 1] = '\0';
        findPathHelper(x, y - 1, grid, size, paths, pathCount, newMove, visited);
        visited[x][y] = 0;
    }

    if (y + 1 < size && !visited[x][y + 1] && grid[x][y + 1] == 1) {
        visited[x][y] = 1;
        char newMove[100];
        strcpy(newMove, move);
        newMove[strlen(move)] = 'R';
        newMove[strlen(move) + 1] = '\0';
        findPathHelper(x, y + 1, grid, size, paths, pathCount, newMove, visited);
        visited[x][y] = 0;
    }

    if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == 1) {
        visited[x][y] = 1;
        char newMove[100];
        strcpy(newMove, move);
        newMove[strlen(move)] = 'U';
        newMove[strlen(move) + 1] = '\0';
        findPathHelper(x - 1, y, grid, size, paths, pathCount, newMove, visited);
        visited[x][y] = 0;
    }
}

void findPath(int** grid, int size, char*** paths, int* pathCount) {
    int** visited = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        visited[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            visited[i][j] = 0;
        }
    }

    if (grid[0][0] == 1) {
        findPathHelper(0, 0, grid, size, paths, pathCount, "", visited);
    }
}

void printPaths(char*** paths, int pathCount) {
    if (pathCount == 0) {
        printf("-1\n");
    } else {
        for (int i = 0; i < pathCount; i++) {
            printf("%s ", paths[i][0]);
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    int grid[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            matrix[i][j] = grid[i][j];
        }
    }

    char*** result = (char***)malloc(100 * sizeof(char**));
    int resultCount = 0;

    findPath(matrix, n, result, &resultCount);
    printPaths(result, resultCount);

    return 0;
}
