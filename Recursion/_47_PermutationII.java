// Problem: Find all the unique permutations from a given nums array. Permutations can be in any order.
// For eg: Input: nums = [2, 2, 1, 1]   ==>  Output: [[2, 2, 1, 1], [2, 1, 2, 1], [2, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 1], [1, 2, 1, 2]]

// Approach: Recursion
/* Solution:
 * 
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _47_PermutationII {
    private static List<List<Integer>> permuteUnique(int[] nums){
        List<List<Integer>> myList = new ArrayList<>();
        Arrays.sort(nums);
        boolean[] mark = new boolean[nums.length];
        findPermutations(nums, myList, new ArrayList<>(), mark);
        return myList;
    }
    private static void findPermutations(int[] nums, List<List<Integer>> myList, List<Integer> ds, boolean[] mark){
        if(ds.size() == nums.length){
            myList.add(new ArrayList<>(ds));
            return;
        }
        int step = 0;
        for(int i = 0; i<nums.length; i++){
            if(step > 0 && nums[i] == nums[i-1]){
                continue;
            }
            if(!mark[i]){
                mark[i] = true;
                ds.add(nums[i]);
                findPermutations(nums, myList, ds, mark);
                step = step + 1;
                ds.remove(ds.size() - 1);
                mark[i] = false;
            }
        }
        return;
    }
    public static void main(String[] args) {
        int[] nums = {2, 2, 1, 1};
        System.out.println(permuteUnique(nums));
    }
}