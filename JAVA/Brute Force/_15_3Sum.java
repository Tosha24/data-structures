// Problem: https://leetcode.com/problems/3sum/

/* Solution:
 * 1. We will iterate through the array and find all the possible combinations of 3 numbers
 * 2. If the sum of the 3 numbers is 0, we will add it to the result
 * 3. We will use a set to avoid duplicates
 * 4. We will sort the list before adding it to the set
 * 5. We will add all the elements of the set to the result and return it.
 */

import java.util.*;

public class _15_3Sum{
    private static List<List<Integer>> threeSum(int[] nums){
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;

        Set<List<Integer>> set = new HashSet<>();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    if(sum == 0){
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]);
                        temp.add(nums[j]);
                        temp.add(nums[k]);
                        Collections.sort(temp);
                        set.add(temp);
                    }
                }
            }
        }
        result.addAll(set);
        return result;
    }
    public static void main(String[] args) {
        int[] nums = {0, 0, 0};
        System.out.println(threeSum(nums));
    }
}

// Time Complexity: O(n^3)
// Space Complexity: O(2*no. of triplets)