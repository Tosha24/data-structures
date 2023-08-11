#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Brute Force Solution : Recursion     ---> TC = O(N * T)  SC = O(N)
class Solution {
    static int solve(int target, vector<int>& coins, int i){
        if(i == 0) return (target % coins[i] == 0);

        int nottake = solve(target, coins, i-1);
        int take = 0;
        if(coins[i] <= target) take = solve(target - coins[i], coins, i);

        return nottake + take;
    }
public:
    static int change(int amount, vector<int>& coins){
        int n = coins.size();
        return solve(amount, coins, n-1);
    }
};


// DP: Memoization  --->    TC = O(N * T)  SC = O(N * T) + O(N)
class Solution_Memoization {
    static int solve(int target, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(i == 0) return (target % coins[i] == 0);

        if(dp[i][target] != -1) return dp[i][target];

        int nottake = solve(target, coins, i-1, dp);
        int take = 0;
        if(coins[i] <= target) take = solve(target - coins[i], coins, i, dp);

        return dp[i][target] = nottake + take;
    }
public:
    static int change(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, coins, n-1, dp);
    }
};


// DP: Tabulation   --->    TC = O(N * T)  SC = O(N * T)
class Solution_Tabulation {
public:
    static int change(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int j = 0; j <= amount; j++){
            if(j % coins[0] == 0) dp[0][j] = 1;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){
                int nottake = dp[i-1][j];

                int take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];

                dp[i][j] = nottake + take;
            }
        }

        return dp[n-1][amount];
    }
};


int main(){
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << Solution::change(amount, coins) << endl;
    cout << Solution_Memoization::change(amount, coins) << endl;
    cout << Solution_Tabulation::change(amount, coins) << endl;
    return 0;
}