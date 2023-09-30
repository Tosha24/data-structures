#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        if(nums[start] <= nums[end]){
            return nums[start];
        }
        while(start < end){
        int mid = start + (end - start)/2;
        if(mid < end && nums[mid] > nums[mid + 1]){
            return nums[mid+1];
        }
        else if(nums[mid] >= nums[start]){
            start = mid + 1;
        }
        else if(nums[mid] <= nums[end]){
            end = mid - 1;
        }
    }   
    return nums[start+1];
    }
};

int main(){
    vector<int> nums = {3,4,5,1,2};
    cout << Solution::findMin(nums) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)