// Problem: Write a program to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all of the following rules: -> Each of the digits 1-9 must occur exactly once in each row. -> Each of the digits 1-9 must occur exactly once in each column. -> Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid. -> The '.' character indicates empty cells.
// For eg:  Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]      ===> Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]

// Approach: Recursion and backtracking

#include <iostream>
#include <vector>
using namespace std;

class _37_SudokuSolver{
public:
    static bool isPossible(int row, int col, vector<vector<char>>& board, char c){
        for(int i = 0; i < 9; i++){
            if(board[i][col] == c) return false;    // checking for c in same col as an empty cell '.' 

            if(board[row][i] == c) return false;    // checking for c in same row as an empty cell '.'
            
            if(board[(3 * (row/3)) + (i/3)][(3 * (col/3)) + (i%3)] == c) return false;      // checking for c in same matrix as an empty cell '.'
        }
        return true;
    }
    static bool solve(vector<vector<char>>& board){
        // Iterate over all cells
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                // If the cell is empty then only we will consider it and try inserting different characters from 1 to 9
                if(board[i][j] == '.'){
                    // For each cell, we assume any characters from all the 1 to 9 characters
                    for(char c = '1'; c <= '9'; c++){
                        // For each character, we check if we can place that character in that particular cell or not
                        if(isPossible(i, j, board, c)){
                            board[i][j] = c;        // We can place the character because it doesn't violate the condition-rule
                            if(solve(board)){
                                // To store the current state, we hence not continue iterating the loop but instead we recursively call the function so that if any character violate the condition-rule, we can check for it's parent state and derive new child state from that state.
                                return true;
                            }
                            else{
                                // This block is only executed when none of the character from 1 to 9 can be placed to current cell[i, j] and hence the solve(board) function returns false
                                board[i][j] = '.';
                            }
                        }
                    }
                    // If we check for all the characters from 1 to 9, still we can't fill the cell, we return false to stop from continuing further and backtrack to the previous state
                    return false;
                }
            }
        }
        // If all the '.' are filled, we then return true (because we get our ans (board filled completely))
        return true;
    }
    static void solveSudoku(vector<vector<char>>& board){
        solve(board);
    }
};

int main(){
    vector<vector<char>> board = {{'5', '3', '.', '.', '7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    _37_SudokuSolver::solveSudoku(board);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}