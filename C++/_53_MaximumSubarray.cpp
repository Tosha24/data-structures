// ✔️ Arrays

// Problem: https://leetcode.com/problems/maximum-subarray/

/* Solution:
 * 1. Iterate through the array and keep adding the elements to the sum.
 * 2. If the sum is greater than the max, update the max.
 * 3. If the sum is less than 0, reset the sum to 0.
 * 4. Return the max.
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxSubArray(vector<int> nums){
    int max = INT_MIN;
    int sum = 0;
    for(int i= 0; i < nums.size(); i++){
        sum = sum + nums[i];
        if(max < sum){
            max = sum;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    return max;
}

int maxSubArray0(vector<int> nums){
    int max = 0;
    for(int i = 0; i < nums.size(); i++){
        int sum = 0;
        for(int j = i; j < nums.size(); j++){
            sum = sum + nums[j];
            max = std::max(max, sum);
        }
    }
    return max;
}

int main() {
    vector<int> nums = {5, 4, -1, 7, 8};
    cout << maxSubArray(nums) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)