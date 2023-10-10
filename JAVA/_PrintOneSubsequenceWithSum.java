// Problem: To print only one subsequence whose sum is equal to the given sum.
// For eg: Input: arr = [1, 2, 1], target = 2   ==>  Output: [1, 1]

// Approach: Recursion
/* Solution:
Here we keep track of stack(that push the current index's element) and also the sum variable(that calculates the sum of elements present in the stack).
 Here we either take the element or not take the element. By adding the element into the stack and adding all the elements in the stack, we consider that element. And by removing the element from the stack and then adding all the remaining elements in the stack, we do not consider that element. We reach end of the array length(for all possible iterations) and then we print the entire subsequence whose sum is equal to the required sum and return true if the sequence is obtained, so that no further function calls can be made to find the other subsequences.
 */

import java.util.Stack;

public class _PrintOneSubsequenceWithSum {
    private static boolean printSubsequence(int index, int[] arr, Stack<Integer> s, int sum, int reqSum){
        if(index >= arr.length){
            if(sum == reqSum){
                System.out.println(s);
                return true;
            }
            else{
                return false;
            }
        }
        
        s.push(arr[index]);
        sum = sum + arr[index];
        if(printSubsequence(index + 1, arr, s, sum, reqSum) == true)
            return true;
        
        int item = s.pop();
        sum = sum - item;
        if(printSubsequence(index + 1, arr, s, sum, reqSum) == true)
            return true;
        return false;
    }
    public static void main(String[] args) {
        int[] arr = {1, 2, 1};
        int reqSum = 2;
        printSubsequence(0, arr, new Stack<Integer>(), 0, reqSum);
    }
}

// Time Complexity: O(2^N)
// Space Complexity: O(N)