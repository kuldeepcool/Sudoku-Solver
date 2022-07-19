# Sudoku-Solver
Simple suduko-solver using backtracking.

## How to use

1. Enter the unsolved sudoku matrix with empty values as 0 in `input.txt`. 
2. Simply compile with `g++` and run the `.exe` to get output in console.

## To get the output in a file follow the step below:
* 1. create new file `output.txt` in the same directory.
* 2. Add this line of code after line 71 in `main`.
* 
    ```c++
    freopen("output.txt", "w", stdout);
    ```
* 3. Compile and run
* 4. Open `output.txt` in Notepad to see the output.
