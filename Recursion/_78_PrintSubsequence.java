// Problem: Print all the subsequences(continous/non-continous which are in order) of an array. 
// For eg: [3, 1, 2] have total 8 subsequences like [], [3], [1], [2], [3, 1], [3, 2], [1, 2], [3, 1, 2]

// Approach: Recursion

import java.util.ArrayList;

public class _78_PrintSubsequence {
    private static void printSequence(int index, int[] arr, ArrayList<Integer> seq) {
        if (index >= arr.length) {  // termination condition: print the sequence when it reaches the end of the array.
            System.out.println(seq);
            return;
        }
        seq.add(arr[index]);    // add the element at index to the sequence (to consider the element)
        printSequence(index + 1, arr, seq);
        seq.remove(seq.size() - 1);     // remove the element that was just added (to not consider the element)
        printSequence(index + 1, arr, seq);
        return;
    }
    public static void main(String[] args) {
        int[] arr = { 8, 3, 6 };
        printSequence(0, arr, new ArrayList<Integer>());
    }
}