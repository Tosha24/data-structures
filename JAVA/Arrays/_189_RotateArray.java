// Problem: https://leetcode.com/problems/rotate-array/

/* Solution:
 * We use three reverse operations to solve this problem:
 * 1. Reverse the first k elements
 * 2. Reverse the rest n - k elements
 * 3. Reverse the whole array
 */

package Arrays;
public class _189_RotateArray{
    private static void reverse(int[] nums, int start, int end){
        int i = start;
        int j = end;
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    }
    private static void rotate(int[] nums, int k){
        k = k % nums.length;
        reverse(nums, 0, nums.length - k - 1);
        reverse(nums, nums.length - k, nums.length-1);
        reverse(nums, 0, nums.length-1);
    }
    public static void main(String[] args){
        int[] nums = {17};
        int k = 6;
        rotate(nums, k);
        for(int i : nums){
            System.out.print(i + ", ");
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)