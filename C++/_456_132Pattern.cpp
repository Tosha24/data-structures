// ✔️ Arrays, Stack  

// Problem: https://leetcode.com/problems/132-pattern/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool find132pattern(vector<int>& nums){
        int n = nums.size();

        if(n < 3) return false;

        stack<int> j;
        int k = INT_MIN;

        for(int i = n - 1; i >= 0; i--){
            if(nums[i] < k) return true;
            else while(!j.empty() && nums[i] > j.top()) {
                k = j.top();
                j.pop();
            }
            j.push(nums[i]);
        }

        return false;
    }
};

int main(){
    vector<int> nums = {3, 5, 0, 3, 4};
    Solution::find132pattern(nums) ? cout << "true" << endl : cout << "false" << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)