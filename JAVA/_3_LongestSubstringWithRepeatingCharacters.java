// Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/* Solution: 
 * 1. Use a hashmap to store the index of each character
 * 2. Use two pointers to keep track of the longest substring
 * 3. If the character is already in the hashmap, move the left pointer to the right of the character
 */

import java.util.*;

public class _3_LongestSubstringWithRepeatingCharacters {
    private static int lengthOfLongestSubstring(String s){
        int longest = 0;

        int l = 0, r = 0;
        int n = s.length();
        
        HashMap<Character, Integer> map = new HashMap<>();

        while(l<=r && r < n){
            if(map.containsKey(s.charAt(r))) l = Math.max(l, map.get(s.charAt(r)) + 1);
            map.put(s.charAt(r), r);
            longest = Math.max(longest, r-l+1);
            r++;
        }

        return longest;
    }
    public static void main(String[] args) {
        String s = "abcabcbb";
        System.out.println(lengthOfLongestSubstring(s)); // 3
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)