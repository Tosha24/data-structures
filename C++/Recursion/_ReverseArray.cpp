// Problem: Reverse the given array
// For eg: Input: arr = [1, 2, 3, 4]   ==>  Output: [4, 3, 2, 1]

// Approach: Recursion

#include <bits/stdc++.h>
using namespace std;

class _ReverseArray {
public:
    static void swap(vector<int>& nums, int low, int high){
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
    }
    static void reverse(vector<int>& nums, int low){
        if(low >= nums.size()/2){
            return;
        }
        swap(nums, low, nums.size() - low - 1);
        reverse(nums, low+1);
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    _ReverseArray::reverse(nums, 0);
    for(int i : nums){
        cout << i << " ";
    }
    return 0;
}

// Time Complexity: O(logN)
// Space Complexity: O(N)