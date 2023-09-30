// Problem: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
    static int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int i = left - 1;

        for(int j = left; j < right; j++){
            if(nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i+1], nums[right]);
        return i+1;
    }
    static int quickSelect(vector<int>& nums, int left, int right, int k){
        int pivotIndex = partition(nums, left, right);

        if(pivotIndex == k) return nums[pivotIndex];
        else if(pivotIndex < k) return quickSelect(nums, pivotIndex+1, right, k);
        else return quickSelect(nums, left, pivotIndex-1, k);

        return -1;
    }
public:
    static int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2, 1, 9, 3, 7, 6};
    int k = 3;
    cout << Solution::findKthLargest(nums, k) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)