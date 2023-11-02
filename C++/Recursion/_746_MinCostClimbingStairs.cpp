// ✔️ Arrays, DP

// Problem: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int solve(vector<int>& cost, int n, vector<int>& dp){
        if(n < 0) return 0;
        if(n == 0) return cost[0];

        if(dp[n] != -1) return dp[n];

        int costV = (n == cost.size()) ? 0 : cost[n];
        int cost1 = costV + solve(cost, n - 1, dp);
        int cost2 = costV + solve(cost, n - 2, dp);
        return dp[n] = min(cost1, cost2);
    }
public:
    static int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return solve(cost, n, dp);
    }
};

int main(){
    vector<int> cost = {10, 15, 20};
    cout << Solution::minCostClimbingStairs(cost) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)