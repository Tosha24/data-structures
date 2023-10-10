// Problem: Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// For eg: Input: s = "aab"    ==>   Output: [["a","a","b"],["aa","b"]]

// Approach: Recursion and backtracking
/* Solution:
 * We start with iterating the string from 0th index.
 * Either we take only 0th index, or we take all indices after 0, one by one (like 0-1, 0-2, 0-3, ... 0-n)
 * We can only take those substrings that are palindrome, So we check everytime we consider some indices.
 * When we find the substring that is palindrome within indices (index to i), we add that substrings to the final ans.
 * We continue this process, and move the iterator to the next non-considering index.
 * We continue to do this until we reach the end of the string.
 * When the iterator reaches end of the string, we add that particular partioned string to the final_ans and backtrack.
 * While backtracking, we remove the last inserted string and continue for the range of indices.
 */

import java.util.List;
import java.util.ArrayList;

public class _131_PalindromePartioning{
    private static List<List<String>> partition(String s) {
        List<List<String>> ans = new ArrayList<>(); // stores the final ans
        List<String> subPalindromes = new ArrayList<>();    // stores each ans at every possible iteration
        partitionString(0, s, subPalindromes, ans);
        return ans;
    }

    private static void partitionString(int index, String s, List<String> subPalindrome, List<List<String>> ans){
        if(index == s.length()){
            ans.add(new ArrayList<>(subPalindrome));
            return;
        }

        for(int i = index; i < s.length(); ++i){    
            if(isPalindrome(s, index, i)){
                subPalindrome.add(s.substring(index, i+1));
                partitionString(i + 1, s, subPalindrome, ans);
                subPalindrome.remove(subPalindrome.size() - 1);
            }
        }
    }

    private static boolean isPalindrome(String s, int start, int end){
        while(start <= end){
            if(s.charAt(start++) != s.charAt(end--)){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        String s = "aab";
        System.out.println(partition(s));
    } 
}