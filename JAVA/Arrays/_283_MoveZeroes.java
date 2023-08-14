// Problem: https://leetcode.com/problems/move-zeroes/

/* Solution:
 * We use two pointers, i and j. i is the slow-runner while j is the fast-runner.
 * We first find the first zero element in the array and store its index in k.
 * Then we initialize the pointer i to k and pointer j to k + 1.
 * We iteratively try to point j to the non-zero element in the array.
 * If we find a non-zero element, we swap the elements at i and j and increment i.
 * We increment j in each iteration (even though no swapping is done).  
 */

package Arrays;
public class _283_MoveZeroes{
    private static void moveZeroes(int[] nums){
        int k = 0;
        while(k < nums.length){
            if(nums[k] == 0){
                break;
            }
            else{
                k = k + 1;
            }
        }

        int i = k, j = k + 1;
        while(i < nums.length && j < nums.length){
            if(nums[j] != 0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i = i + 1;
            }
            j = j + 1;
        }
    }
    public static void main(String[] args){
        int[] nums = {1, 2};
        moveZeroes(nums);
        for(int i : nums){
            System.out.print(i + " ");
        }
    }   
}

// Time Complexity: O(n)
// Space Complexity: O(1)