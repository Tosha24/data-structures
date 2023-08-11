#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static bool search(vector<int>& nums, int target){
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low = low + 1;
                high = high - 1;
                continue;
            }

            if(nums[low] <= nums[mid])
                if(nums[low] <= target && target <= nums[mid]) high = mid - 1;
                else low = mid + 1;
            else
                if(nums[mid] <= target && target <= nums[high]) low = mid + 1;
                else high = mid - 1;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;
    cout << Solution::search(nums, target) << endl;
    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)