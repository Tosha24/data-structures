// Problem: https://leetcode.com/problems/longest-consecutive-sequence/

/* Solution (Brute Force Approach):
 * 1. For each element in the array, check if the next element is in the array by linear searching the entire array.
 * 2. If the next element is in the array, increment the count and next number.
 * 3. Check if the longest is less than the count, if so, update the longest.
 */

/* Solution2 (Better Approach):
 * 1. First we sort the array
 * 2. We keep track of the count and the last number
 * 3. If the next number is the last number + 1, we increment the count
 * 4. If the next number is not the last number + 1, we reset the count to 1
 * 5. We update the longest if the longest is less than the count
 * 6. Return the longest
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    static int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            int next = nums[i] + 1;
            while (linearSearch(nums, next)) {
                count++;
                next = next + 1;
            }
            if (longest < count) {
                longest = count;
            }
        }
        return longest;
    }

    static bool linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    static int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;

        sort(nums.begin(), nums.end());
        int count = 1;
        int lastNumber = nums[0];
        int longest = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] == lastNumber + 1){
                count += 1;
            }
            else if(nums[i] != lastNumber){
                count = 1;
            }
            lastNumber = nums[i];
            longest = max(longest, count);
        }
        return longest;
    }
};

int main() {
    vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    cout << Solution::longestConsecutive(nums) << endl;
    cout << Solution2::longestConsecutive(nums) << endl;
}


/* Brute Force:
    Time Complexity: O(n^2)
    Space Complexity: O(1) */

/* Better Approach:
    Time Complexity: O(nlogn) + O(n)
    Space Complexity: O(1)
 */