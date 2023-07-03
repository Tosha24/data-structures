// Problem: https://leetcode.com/problems/4sum/

/* Solution (Better Solution using Set and hashing)
 * 1. We use a list to store each quadruplets
 * 2. We use a set to store the middle elements (nums[j] + nums[k])
 * 3. We use a hashset to store the fourth element (target - sum)
 * 4. If the hashset contains the fourth element, we add the quadruplet to the list, otherwise we add the kth element to the hashset.
 * 5. Finally, we add the set to the list, so that we don't have duplicate quadruplets
 */

import java.util.*;

public class _18_4Sum{
    private static List<List<Integer>> fourSum(int[] nums, int target){
        Set<List<Integer>> res = new HashSet<>();
        int n = nums.length;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                Set<Long> hashset = new HashSet<>();
                for(int k = j + 1; k < n; k++){
                    long sum = nums[i] + nums[j];
                    sum += nums[k];

                    long fourth = target - sum;
                    if(hashset.contains(fourth)){
                        List<Integer> quad = new ArrayList<>();
                        quad.add(nums[i]);
                        quad.add(nums[j]);  
                        quad.add(nums[k]);
                        quad.add((int)fourth);
                        Collections.sort(quad);

                        res.add(quad);
                    }
                    hashset.add((long) nums[k]);
                }
            }
        }
        List<List<Integer>> ans = new ArrayList<>(res);
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {1,0,-1,0,-2,2};
        int target=0;
        System.out.println(fourSum(nums, target));
    }
}

// Time Complexity: O(N^3 + log(m)) --> n = size of array, m = no. of elements in the set (because we search for the fourth element in the set)
// Space Complexity: O(2*quadruplets) + O(n) ---> O(n) for hashset that stores the middle elements and O(2*quadruplets) for set that stores the quadruplets, and also for the list that stores the quadruplets  