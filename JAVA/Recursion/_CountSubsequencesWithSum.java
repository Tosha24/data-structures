// Problem: To count all the subsequences whose sum is equal to the given sum.
// For eg: Input: arr = [1, 2, 1], target = 2    ==>  Output: 2

// Approach: Recursion
/* Solution:
* Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
* Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. 
* We reach end of the array length(for all possible iterations) and then if the sum is equal to the required sum we return 1 to indicate 1 subsequence. and return 0 to indicate no subsequence with reqSum. At last after performing both the add and remove function we now add both the count of subsequences and return for the previous solution.
 */

import java.util.Stack;

public class _CountSubsequencesWithSum {
    private static int printSubsequence(int index, int[] arr, Stack<Integer> s, int sum, int target) {
        if (index == arr.length) {
            if (sum == target) {
                return 1;
            }
            else
            return 0;
        }
        s.push(arr[index]);
        sum = sum + arr[index];
        int l = printSubsequence(index + 1, arr, s, sum, target);

        int item = s.pop();
        sum = sum - item;
        int r = printSubsequence(index + 1, arr, s, sum, target);
        return l+r;
    }
    public static void main(String[] args) {
        int[] arr = { 1, 2, 1 };
        int target = 2;
        int count = printSubsequence(0, arr, new Stack<Integer>(), 0, target);
        System.out.println(count);
    }
}

// Time Complexity: O(2^N * N)
// Space Complexity: O(N)
