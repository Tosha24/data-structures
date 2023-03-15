// Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
// For eg: Input: nums = [1,2,2]   ==>   Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Approach: Recursion
/* Solution:
 * To avoid duplicates of subsets, we select only those elements in which the current element is not equal to the previous one.
 * To do so, we iterate the loop from current index to the array length, and if the current element is equal to the prev element, we skip considering that element.
 * And we take those elements which are not equal to the prev one.
 * Another Approach: we can also create a set and store all the possible subsets in it. Automatically all the duplicate subsets will be removed from the result. But doing so, it will increase the time complexity as for every element, it has to check the whole set.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class _90_SubsetSumII {
    private static List<List<Integer>> subsetWithDups(int[] nums) {
        List<List<Integer>> nodups = new ArrayList<>();
        Arrays.sort(nums);
        findSubsets(0, nums, nodups, new ArrayList<>());
        return nodups;
    }
    
    private static void findSubsets(int index, int[] arr, List<List<Integer>> nodups, List<Integer> ds){
        nodups.add(new ArrayList<>(ds));

        for(int i = index; i < arr.length; i++){
            if(i != index && arr[i] == arr[i-1]){
                continue;
            }
            ds.add(arr[i]);
            findSubsets(i + 1, arr, nodups, ds);
            ds.remove(ds.size() - 1);
        }
        return;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 2};
        System.out.println(subsetWithDups(nums));
    }
}

// Time Complexity: O(n*2^n)
// Space Complexity: O(2^n)*O(k)
