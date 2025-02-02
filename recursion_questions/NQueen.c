#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSafe(int row, int col, char** board, int n) {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
            return 0;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0) {
        if (board[row][col] == 'Q')
            return 0;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
            return 0;
        row++;
        col--;
    }

    return 1;
}

void solve(int col, char** board, char*** solutions, int* solutionCount, int n) {
    if (col == n) {
        solutions[*solutionCount] = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            solutions[*solutionCount][i] = (char*)malloc((n + 1) * sizeof(char));
            strcpy(solutions[*solutionCount][i], board[i]);
        }
        (*solutionCount)++;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, solutions, solutionCount, n);
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize) {
    char*** solutions = (char***)malloc(1000 * sizeof(char**));
    char** board = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        board[i] = (char*)malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }

    *returnSize = 0;
    solve(0, board, solutions, returnSize, n);

    return solutions;
}

int main() {
    int n = 4;
    int solutionCount;
    char*** solutions = solveNQueens(n, &solutionCount);

    for (int i = 0; i < solutionCount; i++) {
        printf("Arrangement %d\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%s\n", solutions[i][j]);
        }
        printf("\n");
    }

    return 0;
}
