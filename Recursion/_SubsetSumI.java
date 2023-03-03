// Solved in GFG
// Problem: Given a list arr of N integers, print sums of all subsets in it.
// For eg: Input: arr = [2, 3]   ==>  Output: [0, 2, 3, 5]

// Approach: Recursion and backtracking

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class _SubsetSumI{
    private static ArrayList<Integer> subsetSums(ArrayList<Integer> arr, int N){
        ArrayList<Integer> list_of_sums = new ArrayList<>();
        findSubsets(0, arr, N, 0, list_of_sums);
        Collections.sort(list_of_sums);
        return list_of_sums;
    }
    private static void findSubsets(int index, ArrayList<Integer> arr, int N, int sum, ArrayList<Integer> list_of_sums){
        if(index == N){
            list_of_sums.add(sum);
            return;
        }
        
        sum = sum + arr.get(index);
        findSubsets(index + 1, arr, N, sum, list_of_sums);
        
        sum = sum - arr.get(index);
        findSubsets(index + 1, arr, N, sum, list_of_sums);
        return;
    }
    public static void main(String[] args){
        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(2, 3));
        int N = arr.size();
        System.out.println(subsetSums(arr, N));
    }
}