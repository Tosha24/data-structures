#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int solve(vector<vector<int>>& matrix, int i, int j, int m, int n){
        if(j < 0 || j >= m) return 1e6;
        if(i == 0) return matrix[i][j];

        int up = matrix[i][j] + solve(matrix, i-1, j, m, n);
        int left = matrix[i][j] + solve(matrix, i-1, j-1, m, n);
        int right = matrix[i][j] + solve(matrix, i-1, j+1, m, n);

        return min(up, min(left, right));
    }
public:
    static int minFallingPathSum(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            int ans = solve(matrix, m-1, j, m, n);
            mini = min(mini, ans);
        }
        return mini;
    }
};


class Solution_Memoization {
    static int solve(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(j < 0 || j >= m) return 1e6;
        if(i == 0) return dp[i][j] = matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + solve(matrix, i-1, j, m, n, dp);
        int left = matrix[i][j] + solve(matrix, i-1, j-1, m, n, dp);
        int right = matrix[i][j] + solve(matrix, i-1, j+1, m, n, dp);

        return dp[i][j] = min(up, min(left, right));
    }
public:
    static int minFallingPathSum(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            int ans = solve(matrix, m-1, j, m, n, dp);
            mini = min(mini, ans);
        }
        return mini;
    }   
};


class Solution_Tabulation {
public:
    static int minFallingPathSum(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        
    }
};

int main(){
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << Solution::minFallingPathSum(matrix) << endl;
    cout << Solution_Memoization::minFallingPathSum(matrix) << endl;
    return 0;
}