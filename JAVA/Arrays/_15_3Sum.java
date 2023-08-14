// Problem: https://leetcode.com/problems/3sum/

/* Solution (Optimal Solution):
 * 1. Sort the array
 * 2. Use one for loop to iterate through the array
 * 2.1. If the current number at ith index is same as the previous number, continue
 * 3. Use two pointers (j, k) to find the other two numbers
 * 4. If the sum of all three numbers is equal to the 0, add the triplet to the result
 * 4.1. Increment j if the next number is same as the previous number
 * 4.2. Decrement k if the current number is same as the next number (acc to index)
 * 5. If the sum is less than the 0, increment j
 * 6. If the sum is greater than the 0, decrement k
 * 7. Return the result
 */

package Arrays;
import java.util.*;

public class _15_3Sum {
    private static List<List<Integer>> threeSum(int[] nums){
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        int n = nums.length;
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i -1]) continue;
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                if(sum == 0){
                    List<Integer> temp = new ArrayList<>();
                    temp.add(nums[i]);
                    temp.add(nums[j]);
                    temp.add(nums[k]);
                    result.add(temp);

                    j++;
                    k--;
                    
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum < 0) j++;
                else k--;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[] nums = {-1, 0, 1, 2, -1, 4};
        System.out.println(threeSum(nums));
    }
}

// Time Complexity: O(n^2 + nlog(n))      --> n = size of the array, for both pointers: i, (j, k), nlog(n) for sorting
// Space Complexity: O(n)       --> for storing the temp