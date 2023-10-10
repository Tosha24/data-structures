// Problem: https://leetcode.com/problems/minimum-size-subarray-sum/

/* Solution (Optimal Solution): using Sliding window technique
 * 1. In this approach, we keep only the desired subarray between the sliding window.
 * 2. Iterate through the array and keep adding the elements to the sum that are present at index R.
 * 3. If the sum is greater than or equal to the target, update the mini and remove the value at l index. Do this until the sum is not greater than or equal to the target.
 * 4. After each iteration, move only the pointer R to the right till it reaches the end of the array.
 * 5. Return the mini.
*/


public class _209_MinimumSizeSubarraySum {
    private static int minSubArrayLen(int target, int[] nums){
        int mini = Integer.MAX_VALUE;
        int n = nums.length;
        int l = 0; 
        int sum = 0;

        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                mini = Math.min(mini, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return mini == Integer.MAX_VALUE ? 0 : mini;
    }
    public static void main(String[] args){
        int[] nums = {1, 1, 1, 1, 1, 1, 1};
        int target = 11;

        System.out.println(minSubArrayLen(target, nums));
    }
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)