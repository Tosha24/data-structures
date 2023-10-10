// Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/* Solution (Better Approach):
 * 1. Use a HashSet to store the characters in the current substring
 * 2. Use two pointers, l and r, to represent the left and right bound of the current substring
 * 3. If the character at r is not in the HashSet, add it to the HashSet and increment r. The length of the current substring will be between l and r
 * 4. If the character at r is in the HashSet, remove the character at l from the HashSet and increment l. Repeat this until the character at r is not in the HashSet
 * 5. Repeat step 3 and 4 until r reaches the end of the string or l crosses the r pointer.
 */

import java.util.*;

public class _3_LongestSubstringWithoutRepeatingCharacters {
    private static int lengthOfLongestSubstring(String s){
        int longest = 0;
        int l = 0, r = 0;
        int n = s.length();

        Set<Character> myset = new HashSet<>();

        while(l <= r && r < n){
            while(l <= r && myset.contains(s.charAt(r))){
                myset.remove(s.charAt(l));
                l++;
            }
            if(l <= r && !myset.contains(s.charAt(r))){
                myset.add(s.charAt(r));
                longest = Math.max(longest, r - l + 1);
                r++;
            }
        }

        return longest;
    }
    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(lengthOfLongestSubstring(s)); // 3
    }
}

// Time Complexity: O(n) + O(n) = O(2n)
// Space Complexity: O(n)