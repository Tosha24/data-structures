#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// DP: Tabulation Approach  --> TC = O(N*M) ,   SC = O(N*M)
class Solution_Tabulation {
public:
    static int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e6;

                int left = grid[i][j];
                if(j > 0) left += dp[i][j-1];
                else left += 1e6;

                dp[i][j] = min(up, left);
            }
        }
        return dp[m-1][n-1];
    }
};


// DP: Memoization Approach --> TC = O(N*M) ,    SC = O(N*M) + O((M-1)+(N-1)) --> dp matrix
class Solution_Memoization {
private:
    static int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i < 0 || j < 0) return 1e6;
        if(i == 0 && j == 0) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = grid[i][j] + solve(grid, i-1, j, m, n, dp);
        int left = grid[i][j] + solve(grid, i, j - 1, m, n, dp);

        return dp[i][j] = min(up, left);
    }
public:
    static int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, m-1, n-1, m, n, dp);
    }
};


// Brute Force Approach : Recursion  --> TC = O(N * M) ,    SC = O((M - 1) + (N - 1)) --> recursion stack space
class Solution {
private:
    static int solve(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i < 0 || j < 0) return 1e6;
        if(i == 0 && j == 0) return grid[i][j];

        int up = up = grid[i][j] + solve(grid, i - 1, j, m, n);
        int left = grid[i][j] + solve(grid, i, j - 1, m, n);

        return min(up, left);
    }
public:
    static int minPathSum(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        return solve(grid, m-1, n-1, m, n);
    }
};

int main(){
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << Solution::minPathSum(grid) << endl;
    cout << Solution_Memoization::minPathSum(grid) << endl;
    cout << Solution_Tabulation::minPathSum(grid) << endl;
    return 0;
}