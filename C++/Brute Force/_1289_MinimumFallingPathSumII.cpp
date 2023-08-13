#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Recursion    ===>    Time Complexity: O(M*N*N), Space Complexity: O(M*N)
class Solution {
    static int solve(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(j < 0 || j >= m) return 1e6;

        if(i == 0) return grid[i][j];

        int ans = 1e6;
        for(int k = 0; k < n; k++){
            if(k == j) continue;
            ans = min(ans, grid[i][j] + solve(grid, i-1, k, m, n));
        }

        return ans;
    }
public:
    static int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            int ans = solve(grid, n-1, j, m, n);
            mini = min(ans, mini);
        }

        return mini;
    }
};


// DP: Memoization  ==>     Time Complexity: O(M*N*N), Space Complexity: O(M*N) + O((M-1) + (N-1))
class Solution_Memoization {
    static int solve(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(j < 0 || j >= m) return 1e6;

        if(i == 0) return dp[i][j] = grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 1e6;
        for(int k = 0; k < n; k++){
            if(k == j) continue;
            ans = min(ans, grid[i][j] + solve(grid, i - 1, k, m, n, dp));
        }

        return dp[i][j] = ans;
    }
public:
    static int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int j = 0; j < n; j++){
            int ans = solve(grid, n-1, j, m, n, dp);
            mini = min(ans, mini);
        }

        return mini;
    }
};


// DP: Tabulation   ==>     Time Complexity: O(M*N*N), Space Complexity: O(N)
class Solution_Tabulation {
public:
    static int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int j = 0; j < n; j++){
            dp[0][j] = grid[0][j];
        }

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                int ans = 1e6;

                for(int k = 0; k < n; k++){
                    if(k == j) continue;
                    ans = min(ans, grid[i][j] + dp[i-1][k]);
                }

                dp[i][j] = ans;
            }
        }

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            mini = min(dp[n-1][j], mini);
        }

        return mini;
    }
};


int main(){
    vector<vector<int>> grid = {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    cout << Solution::minFallingPathSum(grid) << endl;
    cout << Solution_Memoization::minFallingPathSum(grid) << endl;
    cout << Solution_Tabulation::minFallingPathSum(grid) << endl;
    return 0;
}