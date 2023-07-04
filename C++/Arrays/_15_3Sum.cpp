// Problem: https://leetcode.com/problems/3sum/

/* Solution (Optimal Solution):
 * 1. Sort the array
 * 2. Use one for loop to iterate through the array
 * 2.1. If the current number at ith index is same as the previous number, continue
 * 3. Use two pointers (j, k) to find the other two numbers
 * 4. If the sum of all three numbers is equal to the 0, add the triplet to the result
 * 4.1. Increment j if the next number is same as the previous number
 * 4.2. Decrement k if the current number is same as the next number (acc to index)
 * 5. If the sum is less than the 0, increment j
 * 6. If the sum is greater than the 0, decrement k
 * 7. Return the result
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i -1]) continue;
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            long sum = nums[i];
            sum += nums[j];
            sum += nums[k];
            if(sum == 0){
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                result.push_back(temp);

                j++;
                k--;
                
                while(j < k && nums[j] == nums[j - 1]) j++;
                while(j < k && nums[k] == nums[k + 1]) k--;
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    vector<vector<int>> result = threeSum(nums);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++) cout << result[i][j] << " ";
        cout << endl;
    }
}

// Time Complexity: O(n^2 + nlog(n))      --> n = size of the array, for both pointers: i, (j, k), nlog(n) for sorting
// Space Complexity: O(n)       --> for storing the temp