#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchNext(char** board, char* word, int row, int col, int index, int rows, int cols) {
    if (index == strlen(word))
        return 1;

    if (row < 0 || col < 0 || row >= rows || col >= cols || board[row][col] != word[index] || board[row][col] == '!')
        return 0;

    char temp = board[row][col];
    board[row][col] = '!';

    int top = searchNext(board, word, row - 1, col, index + 1, rows, cols);
    int right = searchNext(board, word, row, col + 1, index + 1, rows, cols);
    int bottom = searchNext(board, word, row + 1, col, index + 1, rows, cols);
    int left = searchNext(board, word, row, col - 1, index + 1, rows, cols);

    board[row][col] = temp;

    return top || right || bottom || left;
}

int exist(char** board, int rows, int cols, char* word) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == word[0] && searchNext(board, word, i, j, 0, rows, cols)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int rows = 3, cols = 4;
    char** board = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        board[i] = (char*)malloc(cols * sizeof(char));
    }

    char inputBoard[3][4] = {{'A', 'B', 'C', 'E'},
                             {'S', 'F', 'C', 'S'},
                             {'A', 'D', 'E', 'E'}};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = inputBoard[i][j];
        }
    }

    char word[] = "ABCCED";

    int result = exist(board, rows, cols, word);

    if (result)
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
