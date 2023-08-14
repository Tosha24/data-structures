// Problem: https://leetcode.com/problems/single-number/

/* Solution:
 * We use bitwise XOR to solve this problem:
 Rule 1. If we take XOR of zero and some bit, it will return that bit
 Rule 2. If we take XOR of two same bits, it will return 0
 * Hence, keeping above two rules in consideration, we can XOR all the elements of the given array together to find the unique non-repeating number.
 */

package Arrays;

public class _136_SingleNumber{
    private static int singleNumber(int[] nums){
        int xor = 0;
        for(int i = 0; i < nums.length; i++){
            xor = xor ^ nums[i];
        }
        return xor;
    }
    public static void main(String[] args){
        int[] nums = {4, 1, 2, 1, 2};
        System.out.println(singleNumber(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)