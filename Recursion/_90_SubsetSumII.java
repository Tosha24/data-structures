// Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set). The solution set must not contain duplicate subsets. Return the solution in any order.
// For eg: Input: nums = [1,2,2]   ==>   Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Approach: Recursion

import java.util.ArrayList;
import java.util.List;

public class _90_SubsetSumII {
    private static List<List<Integer>> subsetWithDups(int[] nums) {
        List<List<Integer>> nodups = new ArrayList<>();
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
