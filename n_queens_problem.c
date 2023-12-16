#include <stdio.h>
#include <stdbool.h>

#define N 8 // Change N to the desired board size

// Function to print the chessboard
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

// Function to print the mirror reflection of the chessboard
void printMirrorSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueensUtil(int board[N][N], int col)
{
    if (col == N)
    {
        // All queens are placed, solution found
        printSolution(board);
        printMirrorSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            res = solveNQueensUtil(board, col + 1) || res;

            // If placing queen in the current position doesn't lead to a solution,
            // then remove the queen from the current position (backtrack)
            board[i][col] = 0;
        }
    }

    return res;
}

// Wrapper function to solve N-Queens problem
void solveNQueens()
{
    int board[N][N];

    // Initialize the board
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueensUtil(board, 0))
        printf("Solution does not exist for N=%d.\n", N);
}

int main()
{
    solveNQueens();
    return 0;
}
