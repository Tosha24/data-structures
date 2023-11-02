// Arrays, HashSet, Sorting, Sliding Window

// Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

import java.util.*;

class _2009_MinimumNumberofOperationstoMakeArrayContinuous {
    public static int minOperations(int[] nums) {
        int maxi = 0;
        int count = 0; 
        int n = nums.length - 1; 
        int l = 0; 

        Arrays.sort(nums); 

        for (int i = 0; i < nums.length; i++) {
            if (i + 1 < nums.length && nums[i] == nums[i + 1]) {
                continue;
            }
            nums[l++] = nums[i];
        }

        for (int i = 0, j = 0; i < l; i++) {
            while (j < l && (nums[j] - nums[i]) <= n) {
                count++;
                j++;
            }
            maxi = Math.max(maxi, count);
            count--;
        }

        return nums.length - maxi;
    }    
    public static void main(String[] args) {
        int[] nums = {1, 10, 100, 1000};
        System.out.println(minOperations(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)