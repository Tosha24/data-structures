// Problem: https://leetcode.com/problems/longest-consecutive-sequence/

/* Solution (Optimal Solution):
 * 1. Create a hashset and add all the elements in the array to the hashset
 * 2. Iterate through the array and check if the hashset contains the element - 1
 * 3. If the hashset does not contain the element - 1, then we know that the element is the start of a sequence
 * 4. We then check how long the sequence is by incrementing the element by 1 and checking if the hashset contains the element + 1
 * 5. We keep incrementing the element by 1 until the hashset does not contain the element + 1  and we know that the sequence has ended
 * 6. We then update the longest variable to the length of the sequence if the length of the sequence is greater than the longest variable
 * 7. We return the longest variable
 */

package Arrays;
import java.util.*;

public class _128_LongestConsecutiveSequence {
    private static int longestConsecutive(int[] nums){
        Set<Integer> hashset = new HashSet<>();

        int n = nums.length;

        for(int i = 0; i < n; i++){
            hashset.add(nums[i]);
        }

        int longest = 0;
        for(int i = 0; i < n; i++){
            if(!hashset.contains(nums[i] - 1)){
                int count = 1;
                int x = nums[i];

                while(hashset.contains(x + 1)){
                    count = count + 1;
                    x += 1;
                }

                longest = Math.max(longest, count);
            }
        }
        return longest;
    }
    public static void main(String[] args) {
        int[] nums = { 100, 4, 200, 1, 3, 2};
        System.out.println(longestConsecutive(nums));
    }
}

// Time Complexity: O(n)
// Space Complexity: O(n)