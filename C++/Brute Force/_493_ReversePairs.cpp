// Problem: https://leetcode.com/problems/reverse-pairs/

/* Solution (Brute Force):
 * 1. We use two for loops to check every possible pairs.
 * 2. If the first element is greater than twice of the second element, we can increase the count.
 * 3. Return the count.
 */

#include <iostream>
#include <vector>
using namespace std;

int reversePairs(vector<int>& nums){
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            if(nums[i] > 2 * nums[j]){
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {2, 4, 3, 5, 1};
    cout << reversePairs(nums) << endl;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)