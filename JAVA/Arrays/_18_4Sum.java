// Problem: https://leetcode.com/problems/4sum/

/* Solution (Optimal Solution):
 * 1. Sort the array
 * 2. Use two nested for loops to iterate through the array
 * 2.1. If the current number at both i and j index is same as the previous number, continue
 * 3. Use two pointers (k, l) to find the other two numbers
 * 4. If the sum of all four numbers is equal to the target, add the quadruplet to the result
 * 4.1. Increment k if the next number is same as the previous number
 * 4.2. Decrement l if the current number is same as the next number (acc to index)
 * 5. If the sum is less than the target, increment k
 * 6. If the sum is greater than the target, decrement l
 * 7. Return the result
 */

package Arrays;
import java.util.*;

public class _18_4Sum {
    private static List<List<Integer>> fourSum(int[] nums, int target){
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);

        int n = nums.length;

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;
                while(k < l){
                    long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        List<Integer> temp = new ArrayList<>(Arrays.asList(nums[i], nums[j], nums[k], nums[l]));
                        result.add(temp);
                        
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k - 1]) k++;
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
                }
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int[] nums = {2147483647, 2147483647, 2147483647, 2147483647, 2147483647};
        int target = 2147483647;
        System.out.println(fourSum(nums, target));
    }
}

// Time Complexity: O(n^3)      --> n = size of the array, for all three pointers: i, j, (k, l)
// Space Complexity: O(no. of quadruplets)  --> as we only use extra temp list to store quadruplets 