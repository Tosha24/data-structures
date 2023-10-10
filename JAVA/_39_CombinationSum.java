// Problem: Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. The same number may be chosen from candidates an unlimited number of times.
// For eg: Input: candidates = [2,3,6,7], target = 7   ==>   Output: [[2,2,3],[7]]

// Approach: Recursion
/* Solution: 
 * We continue choosing the same index, until we find that either the target gets zero(means our solution is inside data structure) or the current element is greater than the target we need to find (means we cannot choose that element because it will get bigger than the target). 
 * On each function call (for the same index), we keep decreasing the target variable until the target is zero or is less than the current element in the array. After finding for the same index, we find for the next index. We continue finding for the next index, until our index reaches the maximum of the array size.
 */

import java.util.ArrayList;
import java.util.List;

public class _39_CombinationSum{
    private static List<List<Integer>> combinationSum(int[] candidates, int target){
        List<List<Integer>> myList = new ArrayList<List<Integer>>();
        printCombination(0, candidates, target, myList, new ArrayList<>());
        return myList;
    }
    private static void printCombination(int index, int[] arr, int target, List<List<Integer>> myList, List<Integer> ds){
        if(index == arr.length){
            if(target == 0){
                myList.add(new ArrayList<>(ds));
            }
            return;
        }
        if(arr[index] <= target){
            ds.add(arr[index]);
            printCombination(index, arr, target - arr[index], myList, ds);
            ds.remove(ds.size() - 1);
        }
        printCombination(index + 1, arr, target, myList, ds);
        return;
    }
    public static void main(String[] args){
        int[] arr = {2, 3, 6, 7};
        int target = 7;
        List<List<Integer>> finalList = combinationSum(arr, target);
        System.out.println(finalList);
    }   
}

// Time Complexity: O(2^n * k)
// Space Complexity: O(k*n)