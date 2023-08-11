#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Brute Force Approach: Recursion  --->    TC = O(N * T),    SC = O(N) --> recursion stack space
class Solution {
private:
    static int solve(vector<int>& coins, int target, int i){
        if(i == 0)
            if(target % coins[i] == 0) return target / coins[i];
            else return 1e6;

        int nottake = 0 + solve(coins, target, i-1);

        int take = INT_MAX;
        if(coins[i] <= target) take = 1 + solve(coins, target - coins[i], i);

        return min(take, nottake);
    }
public:
    static int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        return solve(coins, amount, n-1);
    }
};


// DP: Memoization  --->    TC = O(N * T),    SC = O(N * T) + O(N)
class Solution_Memoization {
    static int solve(vector<int>& coins, int target, int i, vector<vector<int>>& dp){
        if(i == 0)
            if(target % coins[i] == 0) return target / coins[i];
            else return 1e6;

        if(dp[i][target] != -1) return dp[i][target];

        int nottake = 0 + solve(coins, target, i-1, dp);

        int take = INT_MAX;
        if(coins[i] <= target) take = 1 + solve(coins, target - coins[i], i, dp);

        return dp[i][target] = min(take, nottake);
    }
public:
    static int coinChange(vector<int>& coins, int amount){
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(coins, amount, n - 1, dp);
    }
};


// DP: Tabulation  --->    TC = O(N * T),    SC = O(N * T)
class Solution_Tabulation {
public:
    static int coinChange(vector<int>& coins, int amount){
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int j = 0; j <= amount; j++){
            if(j%coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = 1e6;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int nottake = dp[i-1][j];

                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + dp[i][j - coins[i]];

                dp[i][j] = min(take, nottake);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e6) return -1;

        return ans;
    }
};

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << Solution::coinChange(coins, amount) << endl;
    cout << Solution_Memoization::coinChange(coins, amount) << endl;
    cout << Solution_Tabulation::coinChange(coins, amount) << endl;
    return 0;
}