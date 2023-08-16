// Problem: https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    static vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < n; i++){
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();      // Checking the limit of sliding window if followed

            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();  // removing elements that are smaller than the current element

            dq.push_back(i);

            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = Solution::maxSlidingWindow(nums, k);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)