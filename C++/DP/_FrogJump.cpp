#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    // Memoization: TC - O(N),  SC - O(N)
    static int frogJump(int n, vector<int>& height){
        vector<int> dp(n, -1);

        return jump(n-1, height, dp);
    }
    static int jump(int ind, vector<int>& height, vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int jumpTwo = INT_MAX;
        int jumpOne = jump(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);

        if(ind > 1) jumpTwo = jump(ind - 2, height, dp) + abs(height[ind] - height [ind - 2]);

        return dp[ind] = min(jumpOne, jumpTwo);
    }
};

class Solution2_Tabulation {
public:
    // Tabulation: TC - O(N),   SC - O(N)
    static int frogJump(int n, vector<int>& height){
        int jumpTwo = INT_MAX;
        vector<int> dp(n);

        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
            if(i > 1) jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);

            dp[i] = min(jumpOne, jumpTwo);
        }
        return dp[n-1];
    }
};

class Solution3_SO {
public:
    // Space Optimization:  TC - O(N),  SC - O(1)
    static int frogJump(int n, vector<int>& height) {
        int prev2 = 0, prev = 0;
        int jumpTwo = INT_MAX;

        for(int i = 1; i < n; i++){
            int jumpOne = prev + abs(height[i] - height[i - 1]);
            if(i > 1) jumpTwo = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

int main(){
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    cout << Solution::frogJump(n - 1, height) << endl;
    cout << Solution2_Tabulation::frogJump(n - 1, height) << endl;
    cout << Solution3_SO::frogJump(n - 1, height) << endl;
    return 0;
}