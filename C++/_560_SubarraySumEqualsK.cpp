// Problem: https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    static int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int,int> mpp;

        int presum = 0, count = 0;
        mpp[0] =  1;
        for(int i = 0; i < n; i++){
            presum += nums[i];
            int remove = presum - k;

            count += mpp[remove];

            mpp[presum] += 1;
        }

        return count;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << Solution::subarraySum(nums, k) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)