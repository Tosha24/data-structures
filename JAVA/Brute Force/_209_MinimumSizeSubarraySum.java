// Problem: https://leetcode.com/problems/minimum-size-subarray-sum/

/* Solution (Brute Force):
 * 1. In this approach, we iterate through the array and keep adding the elements to the sum that are present at index j.
 * 2. If the sum is greater than or equal to the target, update the mini and break the loop.
 * 3. Here we first create all the possible subarrays by iterating using 2 pointers simultaneously.
 * 4. Return the mini.
 */

public class _209_MinimumSizeSubarraySum {
    private static int minSubArrayLen(int target, int[] nums){
        int n = nums.length;
        int mini = Integer.MAX_VALUE;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum >= target){
                    mini = Math.min(mini, j - i + 1);
                    break;
                }
            }
        }

        return mini == Integer.MAX_VALUE ? 0 : mini;
    }
    public static void main(String[] args) {
        int[] nums = {2,3,1,2,4,3};
        int target = 7;

        System.out.println(minSubArrayLen(target, nums));
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)