// ✔️ Arrays

// Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int search(vector<int>& nums, int target){
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[low] <= nums[mid]){    // left half is sorted (between low to mid)
                if(nums[low] <= target && target <= nums[mid]) high = mid - 1;      // target is in between low and mid so move high to left half   
                else low = mid + 1; // target is not in between so move low pointer to right half
            }
            else{   // nums[mid] <= nums[high]     // right half is sorted (between mid to high)
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;      // target is in between mid and high so move low to right half
                else high = mid - 1;    // target is not in between so move high pointer to left half
            }
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << Solution::search(nums, target) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)