// Problem: Check if the number is palindrome
// For eg: 121 is a palindrome

// Approach: Recursion

public class _PalindromeRecursion {
    private static boolean isPalindrome(int[] nums, int low){
        int n = nums.length;
        if(low >= n/2){
            return true;
        }
        if(nums[low] != nums[n - low - 1]){
            return false;
        }
        return isPalindrome(nums, low + 1);
    }
    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 2, 1};
        System.out.println(isPalindrome(nums, 0));
    }
}

// Time Complexity: O(logN)
// Space Complexity: O(N) + O(logN)
