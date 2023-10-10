// Problem: To print the subsequences whose sum is equal to the given sum.
// For eg: Input: [1, 2, 1], target = 2   ==>   Output: [1, 1], [2]

// Approach: Recursion
/* Solution:
 * Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
 * Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. We reach end of the array length(for all possible iterations) and then we print the entire subsequence whose sum is equal to the required sum.
 */

import java.util.Stack;

public class _PrintSubsequenceWithSum {
    private static void printSubsequence(int index, int[] arr, Stack<Integer> s, int sum, int reqSum) {
        if (index == arr.length) {
            if (sum == reqSum) {
                System.out.println(s);
            }
            return;
        }
        s.push(arr[index]);
        sum = sum + arr[index];
        printSubsequence(index + 1, arr, s, sum, reqSum);

        int item = s.pop();
        sum = sum - item;
        printSubsequence(index + 1, arr, s, sum, reqSum);
        return;
    }
    public static void main(String[] args) {
        int[] arr = { 1, 2, 1 };
        int reqSum = 2;
        printSubsequence(0, arr, new Stack<Integer>(), 0, reqSum);
    }
}

// Time Complexity: O(2^N * N)
// Space Complexity: O(N)