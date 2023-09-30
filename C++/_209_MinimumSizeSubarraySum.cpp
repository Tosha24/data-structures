// Problem: https://leetcode.com/problems/minimum-size-subarray-sum/

/* Solution (Optimal Solution): using Sliding window technique
 * 1. In this approach, we keep only the desired subarray between the sliding window.
 * 2. Iterate through the array and keep adding the elements to the sum that are present at index R.
 * 3. If the sum is greater than or equal to the target, update the mini and remove the value at l index. Do this until the sum is not greater than or equal to the target.
 * 4. After each iteration, move only the pointer R to the right till it reaches the end of the array.
 * 5. Return the mini.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minSubArrayLen(int target, vector<int>& nums){
        int mini = INT_MAX;
        int n = nums.size();
        int l = 0; 
        int sum = 0;

        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                mini = min(mini, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    int target = 11;

    cout << Solution::minSubArrayLen(target, nums) << endl;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)