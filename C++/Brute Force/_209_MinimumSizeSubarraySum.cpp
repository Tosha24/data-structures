// Problem: https://leetcode.com/problems/minimum-size-subarray-sum/

/* Solution (Brute Force):
 * 1. In this approach, we iterate through the array and keep adding the elements to the sum that are present at index j.
 * 2. If the sum is greater than or equal to the target, update the mini and break the loop.
 * 3. Here we first create all the possible subarrays by iterating using 2 pointers simultaneously.
 * 4. Return the mini.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum >= target){
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;

    cout << Solution::minSubArrayLen(target, nums) << endl;
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)