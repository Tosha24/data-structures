// Problem: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. The solution set must not contain duplicate combinations.
// For eg: Input: candidates = [10,1,2,7,6,1,5], target = 8   ==>   Output: [[1,1,6], [1,2,5], [1,7], [2,6]]

// Approach: Recursion

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class _40_CombinationSumII {
    private static List<List<Integer>> combinationSum(int[] candidates, int target){
        Set<List<Integer>> mySet = new HashSet<>();
        Arrays.sort(candidates);
        findCombinations(0, candidates, target, mySet, new ArrayList<>());
        List<List<Integer>> myList = new ArrayList<>(mySet);
        return myList;
    }
    private static void findCombinations(int index, int[] arr, int target, Set<List<Integer>> mySet, List<Integer> ds){
        if(index == arr.length){
            if(target == 0){
                mySet.add(new ArrayList<>(ds));
            }
            return;
        }
        if(arr[index] <= target){
            ds.add(arr[index]);
            findCombinations(index + 1, arr, target - arr[index], mySet, ds);
            ds.remove(ds.size() - 1);
        }
        findCombinations(index + 1, arr, target, mySet, ds);
        return;
    }
    public static void main(String[] args) {
        int[] arr = {10, 1, 2, 7, 6, 1, 5};
        int target = 8;
        List<List<Integer>> myList = combinationSum(arr, target);
        System.out.println(myList);
    }
}

// Time Complexity: O(2^n * k)
// Space Complexity: O(n*k)