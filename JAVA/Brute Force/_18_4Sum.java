// Problem: https://leetcode.com/problems/4sum/

/* Solution (Brute Force):
 * 1. We use 4 pointer approach to solve the problem. The most naive approach.
 * 2. We iterate over the array using those 4 pointers.
 * 3. We check if the sum of those 4 pointers is equal to the target sum.
 * 4. If yes, then we add those 4 numbers to the set after sorting internally (this will avoid duplicates).
 * 5. Finally, we convert set into list. 
 */

import java.util.*;

public class _18_4Sum {
    private static List<List<Integer>> fourSum(int[] nums, int target){
        Set<List<Integer>> quad = new HashSet<>();
        int n = nums.length;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];

                        if(sum == target){
                            List<Integer> temp = new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                            Collections.sort(temp);
                            quad.add(temp);
                        }
                    }
                }
            }
        }
        List<List<Integer>> result = new ArrayList<>(quad);
        return result;
    }
    public static void main(String[] args) {
        int[] nums = {1,0,-1,0,-2,2};
        int target=0;
        System.out.println(fourSum(nums, target));
    }
}

// Time Complexity: O(N^4)
// Space Complexity: O(2 * no of quadruplets) ----> here we use extra set to store the quadruplets in order to avoid duplicates