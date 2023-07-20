#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;


// Memoization:     TC: O(n),    SC: O(n)
class Solution_Memoization {
public:
    static int solve(vector<int> &nums, int ind, vector<int> &dp){
        if(dp[ind] != -1) return dp[ind];
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        int pick = nums[ind] + solve(nums, ind - 2, dp);
        int skip = 0 + solve(nums, ind - 1, dp);
        return dp[ind] = max(pick, skip);
    }
    static int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }
};


// Tabulation:      TC: O(n),   SC: O(n)
class Solution_Tabulation {
public:
    static int solve(vector<int> &nums, int ind, vector<int> &dp){
        dp[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int pick = nums[i];
            if(i > 1){
                pick += dp[i - 2];
            }
            int skip = dp[i - 1];

            dp[i] = max(pick, skip);
        }

        return dp[nums.size() - 1];
    }
    static int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n-1, dp);
    }
};

// Space Optimization:   TC: O(n),    SC: O(1)
class Solution_SpaceOptimization {
public:
    static int maximumNonAdjacentSum(vector<int> &nums){
        int n = nums.size();
        
        return solve(nums, n-1);
    }
    static int solve(vector<int> &nums, int ind){
        int prev = nums[0];
        int prev_2 = 0;

        for(int i = 1; i < nums.size(); i++){
            int pick = nums[i];
            if(i > 1){
                pick += prev_2;
            }
            int skip = 0 + prev;
            
            int curr = max(pick, skip);
            
            prev_2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main(){
    vector<int> nums = {2, 1, 4, 9};
    cout << Solution_Memoization::maximumNonAdjacentSum(nums) << endl;
    cout << Solution_Tabulation::maximumNonAdjacentSum(nums) << endl;
    cout << Solution_SpaceOptimization::maximumNonAdjacentSum(nums) << endl;
    return 0;
}