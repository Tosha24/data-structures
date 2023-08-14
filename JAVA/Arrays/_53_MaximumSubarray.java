// Problem: https://leetcode.com/problems/maximum-subarray/

/* Solution (Optimal Solution):
 * 1. Iterate through the array and keep adding the elements to the sum.
 * 2. If the sum is greater than the max, update the max.
 * 3. If the sum is less than 0, reset the sum to 0.
 * 4. Return the max.
 */

package Arrays;
public class _53_MaximumSubarray {
    private static int maxSubArray(int[] nums){
        /** Optimal Solution
            @param nums: array of integers
            @return max: maximum sum of the subarray
         */
        int max = Integer.MIN_VALUE;
        int sum = 0;
        for(int i= 0; i < nums.length; i++){
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
    private static int maxSubArray0(int[] nums){
        /** Better Solution -> O(n^2)
         * @param nums: array of integers
         * @return max: maximum sum of the subarray
         */
        int max = 0;
        for(int i = 0; i < nums.length; i++){
            int sum = 0;
            for(int j = i; j < nums.length; j++){
                sum = sum + nums[j];
                max = Math.max(max, sum);
            }
        }
        return max;
    }
    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(maxSubArray0(nums));
        System.out.println(maxSubArray(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)