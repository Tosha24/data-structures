// Problem: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

/* Solution:
 * We traverse through the array and check if nums[i] > nums[(i+1) % nums.length].
 * If yes, we increment count by 1.
 * Finally, we check if count <= 1.
 */

public class _1752_CheckIfArrayIsSortedRotated{
    public static boolean check(int[] nums){
        int count = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > nums[(i+1) % nums.length]){
                count = count + 1;
            }
        }
        return count <= 1;
    }
    public static void main(String[] args){
        int[] nums = {3, 4, 4, 1, 1};
        System.out.println(check(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)