// Problem: https://leetcode.com/problems/maximum-product-subarray/


#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int prefix = 1, suffix = 1;

        for(int i = 0; i < n; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};

int main(){
    vector<int> nums = {2,3,-2,4};
    cout << Solution::maxProduct(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)