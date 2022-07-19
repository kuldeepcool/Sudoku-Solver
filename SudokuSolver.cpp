#include <iostream>
#include <cmath>
using namespace std;

bool isValid(int board[9][9], int i, int j, int num, int n){
    // Row and Column Check
    for (int x = 0; x < n; ++x)
        if ((board[i][x] == num) || (board[x][j] == num))
            return false;
    
    // Calculate starting points of submatrix
    int rn = sqrt(n);
    int s_i = i - (i % rn);
    int s_j = j - (j % rn);

    // Submatrix Check
    for (int x = s_i; x < s_i + rn; ++x){
        for (int y = s_j; y < s_j + rn; ++y){
            if (board[x][y] == num)
                return false;
        }
    }
    return true;
}

void printBoard(int board[9][9], int n){   // Print solved sudoku on console

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool SudokuSolver(int board[][9], int i, int j, int n)
{
    // Base Case
    if (i == n)
    {
        printBoard(board, n);
        return true;
    }

    // Corner Case 1 -> check for Bounds
    if (j == n)
        return SudokuSolver(board, i + 1, 0, n);

    // Corner Case 2 -> if cell is pre-set move forward
    if (board[i][j] != 0){
        return SudokuSolver(board, i, j + 1, n);
    }

    // Start filling values
    for (int num = 1; num <= 9; ++num){    // Numbers are from 1 to 9 in sudoku
        if (isValid(board, i, j, num, n)){
            board[i][j] = num;
            bool sub = SudokuSolver(board, i, j + 1, n);
            if (sub)
                return true;

            // Backtrack -> undo changes
            board[i][j] = 0;
        }
    }
    return false;
}

int main(){

    freopen("input.txt", "r", stdin);       //To read the board matrix from 'input.txt'.
    
    int n = 9;                              // can be changed according to board size.

    int board[9][9];                        // our board/sudoku

    cout << "<-------------Sudoku Solver------------->\n\n";
    cout << "Given Sudoku to solve is :-\n";

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> board[i][j];             // taking input of pre-set values on the board from 'input.txt'
            cout << board[i][j]<<" ";       //At the same time displaying the unsolved board
        }                                   // zeroes represent empty space
        cout<<"\n";
    }
    cout<<"\n\n";

    //cout<<"After Solving :- \n";
    if(SudokuSolver(board, 0, 0, n))cout<<"Solved\n";           // calling the solver; arguments - board, position of first cell, grid-size
    else cout<<"Cannot Solve!!! -> Check input\n";
    return 0;
}