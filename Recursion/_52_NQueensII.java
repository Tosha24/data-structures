// Problem: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. The queens attack each other when either another queen is in its any diagonal, or in the same row or same column with other queen. Given an integer n, return count of all distinct solutions to the n-queens puzzle.
// For eg: Input: n = 4     ==>   Output: 2

// Approach: Recursion and backtracking

import java.util.List;
import java.util.ArrayList;
public class _52_NQueensII {
    // Initial function : It creates board, and initialize the whole board with '.' to indicate empty cell.
    private static int solveNQueens(int n){
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        List<List<String>> ans = new ArrayList<List<String>>();
        placeQueens(0, n, board, ans);
        return ans.size();
    }

    // Main function: It will place queens column wise only when it does not attack the other queens.
    private static void placeQueens(int col, int n, char[][] board, List<List<String>> ans){
        // If the column pointer completed placing queens in all columns we add that as a solution.
        if(col == n){
            ans.add(matrixToString(board));
            return;
        }
        
        // It will iterate over row and check for each row if the queen can be placed in that particular row and column.
        for(int row = 0; row < n; row++){
            if(isPossible(row, col, board, n)){     // If true, adds the queen to that cell and then go to next column
                board[row][col] = 'Q';      // Places the queen in cell
                placeQueens(col + 1, n, board, ans);    // calls the function for the next column if the queen has been placed
                board[row][col] = '.';      // Removes the queen if no further queens can be placed satisfying the rules
            }
        }
    }

    // Answer: Converts all the rows of final board[][] matrix into the different strings and append to the list
    private static List<String> matrixToString(char[][] board){
        List<String> ans = new ArrayList<String>();
        for(int r = 0; r < board.length; r++){
            String str = "";
            for(int c = 0; c < board.length; c++){
                str = str + board[r][c];
            }
            ans.add(str);
        }
        return ans;
    }

    // Condition function: Check if the queen to be placed does not attack other queens
    private static boolean isPossible(int row, int col, char[][] board, int n){
        // Checking upper left diagonal
        int r = row;
        int c = col;

        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r = r - 1;
            c = c - 1;
        }

        // Checking previous left row
        r = row;
        c = col;

        while(c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            c = c - 1;
        }

        // Checking bottom left diagonal
        r = row;
        c = col;

        while(r < n && c >= 0){
            if(board[r][c] == 'Q'){
                return false;
            }
            r = r + 1;
            c = c - 1;
        }

        // If no queens are found that are conflicting the condition, then return true
        return true;
    }
    public static void main(String[] args){
        int n = 4;
        System.out.println(solveNQueens(n));
    }
}
