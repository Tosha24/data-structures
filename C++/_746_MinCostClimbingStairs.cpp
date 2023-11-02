// ✔️ Arrays, DP

// Problem: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{
public:
    static int minCostClimbingStairs(vector<int>& cost){
        int n = cost.size();

        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i <= n; i++){
            int costV = (i == n) ? 0 : cost[i];
            dp[i] = min(dp[i - 1], dp[i - 2]) + costV;
        }
        return dp[n];
    }
};

int main(){
    vector<int> cost = {10, 15, 20};
    cout << Solution::minCostClimbingStairs(cost) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)