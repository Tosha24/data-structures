// Problem: https://leetcode.com/problems/3sum/

/* Solution (Better Solution using Set and hashing)
 * 1. We use a list to store each triplets
 * 2. We use a set to store the middle elements (nums[j])
 * 3. We use a hashset to store the third element (-1 * sum)
 * 4. If the hashset contains the third element, we add the triplet to the list, otherwise we add the jth element to the hashset.
 * 5. Finally, we add the set to the list, so that we don't have duplicate triplets
 */

import java.util.*;

public class _15_3Sum {
    private static List<List<Integer>> threeSum(int[] nums){
        Set<List<Integer>> triplets = new HashSet<>();
        int n = nums.length;
        for(int i = 0; i < n; i++){
            Set<Long> hashset = new HashSet<>();
            for(int j = i + 1; j < n; j++){
                long sum = nums[i];
                sum += nums[j];
                long third = (-1) * sum;
                if(hashset.contains(third)){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add((int) third);
                    Collections.sort(temp);
                    triplets.add(temp);
                }
                hashset.add((long)nums[j]);
            }
        }
        List<List<Integer>> result = new ArrayList<>(triplets);
        return result;
    }
    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, -4}; 
        System.out.println(threeSum(nums));
    }
}

// Time Complexity: O(N^2 + log(m)) --> n = size of array, m = no. of elements in the set (because we search for the third element in the set)
// Space Complexity: O(2*triplets) + O(n) ---> O(n) for hashset that stores the middle elements and O(2*triplets) for set that stores the triplets, and also for the list that stores the triplets  