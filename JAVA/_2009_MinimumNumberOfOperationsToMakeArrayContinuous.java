// Arrays, HashSet, Sorting, Sliding Window

// Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/

import java.util.*;

class _2009_MinimumNumberofOperationstoMakeArrayContinuous {
    public static int minOperations(int[] nums){
        int n = nums.length;
        Set<Integer> set = new HashSet<>();
        for(int num: nums){
            set.add(num);
        }
        int[] arr = new int[set.size()];
        int idx = 0;
        for(int num: set){
            arr[idx++] = num;
        }

        Arrays.sort(arr);
        int res = n;

        int r = 0;

        for(int l = 0; l < arr.length; l++){
            while(r < arr.length && arr[r] < arr[l] + n){
                r += 1;
            }
            int window = r - l;
            res = Math.min(res, n - window);
        }
        return res;
    }
    public static void main(String[] args) {
        int[] nums = {1, 10, 100, 1000};
        System.out.println(minOperations(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)