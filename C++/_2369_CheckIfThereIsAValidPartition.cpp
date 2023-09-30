#include <iostream>
#include <bits/stdc++.h>    
#include <vector>
using namespace std;

class Solution {
    static bool solve(vector<int>& nums, int i, vector<bool>& dp){
        if(i < 0)
            return true;
        
        if(dp[i] != 0)
            return dp[i];

        bool result = false;
        
        if((i - 1) >= 0 && (nums[i] == nums[i-1]))
            result |= solve(nums, i-2, dp);
        
        if((i - 2) >= 0 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2])
            result |= solve(nums, i-3, dp);
        
        if((i - 2) >= 0 && ((nums[i] - 1) == nums[i-1]) && ((nums[i] - 2) == nums[i-2]))
            result |= solve(nums, i-3, dp);

        return dp[i] = result;
    }
public:
    static int validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, 0);
        return solve(nums, n - 1, dp);
    }
};

int main() {
    vector<int> nums = {4, 4, 4, 5, 6};
    cout << Solution::validPartition(nums) << endl;
    return 0;
}
