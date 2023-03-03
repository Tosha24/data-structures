// Problem: Given an integer x, return true if x is a palindrome, and false otherwise.
// For eg: Input: 1211  ==> Output: false

// Approach: Binary Search
/* Solution:
 * We will start from both the ends of the string. If the character at both ends are not same, we return false at any point of the iteration and not continue further.
 * If the character at both ends are same, we increase start pointer and decrease end pointer. and continue the same till we traverse whole string.
 */

public class _9_Palindrome {
    static boolean isPalindrome(int x){
        String str = Integer.toString(x);
        int i = 0;
        int j = str.length() - 1;
        while(i<=j){
            if(str.charAt(i) != str.charAt(j)){
                return false;
            }
            else{
                i = i + 1;
                j = j - 1;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int number = 1211;
        System.out.println(isPalindrome(number));
    }
}

// Time Complexity: O(logn)