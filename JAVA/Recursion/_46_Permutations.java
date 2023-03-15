// Problem: Given an array nums of distinct integers, return all the possible permutations.
// For eg: Input: nums = [1,2,3]   ==>  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Approach: Recursion
/* Solution:
 * Here, we consider all the indices one by one which are not considered in any function call.
 */

import java.util.ArrayList;
import java.util.List;
public class _46_Permutations {
    private static List<List<Integer>> permute(int[] nums){
        List<List<Integer>> myList = new ArrayList<>();
        boolean mark[] = new boolean[nums.length];
        findPermutations(nums, myList, new ArrayList<>(), mark);
        return myList;
    }
    private static void findPermutations(int[] nums, List<List<Integer>> myList, List<Integer> ds, boolean[] mark){
        // Base condition: if the size(ans array) and size(original array) means that is the required ans
        if(ds.size() == nums.length){
            myList.add(new ArrayList<>(ds));
            return;
        }

        // Consider all (0 to n) the non considered indices at every function call
        for(int i = 0; i < nums.length; i++){
            // If the particular value of i is not consider then do consider it
            if(!mark[i]){
                mark[i] = true;
                ds.add(nums[i]);
                findPermutations(nums, myList, ds, mark);
                ds.remove(ds.size() - 1);
                mark[i] = false;
            }
        }
        return;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        System.out.println(permute(nums));
    }
}

// Time Complexity: O(n! * n)
// Space Complexity: O(n) + O(n)