// Problem: https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution{ 
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        int maxi = INT_MIN;

        vector<int> ans;

        for(int i = 0; i < n - k + 1; i++){
            maxi = INT_MIN;
            for(int j = 0; j < k; j++){
                maxi = max(maxi, nums[i+j]);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1};
    int k = 1;
    vector<int> res = Solution::maxSlidingWindow(nums, k);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}

// Time Complexity: O(n*k)
// Space Complexity: O(1)