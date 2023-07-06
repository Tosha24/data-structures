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

import java.util.Arrays;

class Solution {
    private static int longestConsecutive(int[] nums) {
        int longest = 0;
        int n = nums.length;
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

    private static boolean linearSearch(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
}

public class _128_LongestConsecutiveSequence {
    private static int longestConsecutive(int[] nums){
        int n = nums.length;
        if(n == 0 || nums == null) return 0;

        Arrays.sort(nums);
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
            longest = Math.max(longest, count);
        }
        return longest;
    }
    public static void main(String[] args) {
        int[] nums = { 100, 4, 200, 1, 3, 2 };
        System.out.println(longestConsecutive(nums));
    }
}

/* Brute Force:
    Time Complexity: O(n^2)
    Space Complexity: O(1) */

/* Better Approach:
    Time Complexity: O(nlogn) + O(n)
    Space Complexity: O(1)
 */