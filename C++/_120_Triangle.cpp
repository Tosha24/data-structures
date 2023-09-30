#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Brute Force Approach: Recursion --->    TC = O(N*N)  SC = O(N) --> recursive stack
class Solution{
private: 
    static int solve(vector<vector<int>>& triangle, int i, int j, int n){
        if(i == n-1) return triangle[i][j];

        int down = triangle[i][j] + solve(triangle, i+1, j, n);
        int right = triangle[i][j] + solve(triangle, i+1, j+1, n);

        return min(down, right);
    }
public:
    static int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        return solve(triangle, 0, 0, n);
    }
};


// DP: Memoization  --->    TC = O(N*N)  SC = O(N*N) + O(N)
class Solution_Memoization{
private: 
    static int solve(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
        if(i == n-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(triangle, i+1, j, n, dp);
        int right = triangle[i][j] + solve(triangle, i+1, j+1, n, dp);

        return dp[i][j] = min(down, right);
    }
public:
    static int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, 0, 0, n, dp);
    }
};


// DP: Tabulation  --->    TC = O(N*N)  SC = O(N*N)
class Solution_Tabulation {
public:
    static int minimumTotal(vector<vector<int>>& triangle){
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int up = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(up, diagonal);
            }
        }

        return dp[0][0];
    }
};


int main(){
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << Solution::minimumTotal(triangle) << endl;
    cout << Solution_Memoization::minimumTotal(triangle) << endl;
    cout << Solution_Tabulation::minimumTotal(triangle) << endl;
    return 0;
}