// Problem: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int start = 1, end = n - 2;

        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid]; 
            
            if((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << Solution::singleNonDuplicate(nums) << endl;
    return 0;
}

// TIme Complexity: O(logn)
// Space Complexity: O(1)