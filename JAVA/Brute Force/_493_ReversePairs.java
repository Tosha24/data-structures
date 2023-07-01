// Problem: https://leetcode.com/problems/reverse-pairs/

/* Solution (Brute Force):
 * 1. We use two for loops to check every possible pairs.
 * 2. If the first element is greater than twice of the second element, we can increase the count.
 * 3. Return the count.
 */

public class _493_ReversePairs {
    private static int reversePairs(int[] nums){
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            for(int j = i+1; j < nums.length; j++){
                if(nums[i] > 2 * nums[j]){
                    count++;
                }
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int[] nums = {2, 4, 3, 5, 1};
        System.out.println(reversePairs(nums));
    }
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)