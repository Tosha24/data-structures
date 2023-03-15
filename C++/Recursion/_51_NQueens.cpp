// Problem: The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. The queens attack each other when either another queen is in its any diagonal, or in the same row or same column with other queen. Given an integer n, return all distinct solutions to the n-queens puzzle.
// For eg: Input: n = 4     ==>   Output: [["..Q.", "Q...", "...Q", ".Q.."], [".Q..", "...Q", "Q...", "..Q."]]

// Approach: Recursion and backtracking

#include <iostream>
#include <vector>
using namespace std;

class _51_NQueens{
    // Initial function : It creates board, and initialize the whole board with '.' to indicate empty cell.
public:
    static vector<vector<string>> solveNQueens(int n){
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<vector<string>> ans;
        placeQueens(0, n, board, ans);
        return ans;
    }

    // Main function: It will place queens column wise only when it does not attack the other queens.
    static void placeQueens(int col, int n, vector<string>& board, vector<vector<string>>& ans){
        // If the column pointer completed placing queens in all columns we add that as a solution.
        if(col == n){
            ans.push_back(board);
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

    // Condition function: Check if the queen to be placed does not attack other queens
    static bool isPossible(int row, int col, vector<string>& board, int n){
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
};

int main(){
    int n = 4;
    vector<vector<string>> ans = _51_NQueens::solveNQueens(n);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << ", ";
        }
        cout << "]";
    }
    cout << " ]";
    return 0;
}

// Time Complexity: O(N!)
// Space Complexity: O(N^2)