// Arrays [Hint: Assume Monotonic, then check if increasing or decreasing, if neither then false]

// Problem: https://leetcode.com/problems/monotonic-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool isMonotonic(vector<int>& nums){
        bool increasing = true;
        bool decreasing = true;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i+1]){
                increasing = false;
            }
            if(nums[i] < nums[i+1]){
                decreasing = false;
            }
        }
        return increasing || decreasing;
    }
};

int main(){
    vector<int> nums = {1,2,2,3};
    cout << Solution::isMonotonic(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)