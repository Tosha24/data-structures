// Problem: Find the duplicate number in the array, only one repeated number here so return that number
// For eg: Input: nums = [1, 3, 4, 2, 2]   ==>  Output: 2

// Approach: Brute Force 

import java.util.Arrays;
public class _287_FindTheDuplicate {
    static int findDuplicate(int[] nums) {
        Arrays.sort(nums);
        for(int i=0; i<nums.length; i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] array = {1, 3, 4, 2, 2};
        System.out.println(findDuplicate(array));
    }
}
