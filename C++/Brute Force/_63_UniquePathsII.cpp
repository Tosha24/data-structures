#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// DP: Tabulation --> TC = O(N * M) , SC = O(N * M) --> no recursion stack space
class Solution_Tabulation {
public: 
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }   
        }
        return dp[m-1][n-1];
    }
};


// DP: Memoization --> TC = O(N * M) , SC = O(N * M) + O((M - 1) + (N - 1)) ---> where O((M - 1) + (N - 1)) is the recursion stack space
class Solution_Memoization {
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, dp, m-1, n-1);
    }
private:
    static int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j){
        if(i >= 0 && j > 0 && grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(grid, dp, i - 1, j) + solve(grid, dp, i, j - 1);
    }
};

// Brute Force : Recursion --> TC = O(N * M), SC = O((M - 1) + (N - 1)) ---> where O((M - 1) + (N - 1)) is the recursion stack space 
class Solution {
public: 
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(obstacleGrid, m-1, n-1);
    }
private:
    static int solve(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && j > 0 && grid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;

        return solve(grid, i - 1, j) + solve(grid, i, j - 1);
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0, 0, 1},{0,1,0},{0,0,0}};
    cout << Solution::uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << Solution_Memoization::uniquePathsWithObstacles(obstacleGrid) << endl;
    cout << Solution_Tabulation::uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}