// Problem: Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.
// For eg: Input: nums = [7,2,5,10,8], k = 2   ==>   Output: 18

// Approach: Binary Search
/* Solution: 
 * Here we apply binary search in output directly instead of applying to the nums array. We search between the maximum number in the array to the total sum of the array. As our answer will lie between these two values. 
 * We considered maximum in the array as the start value because thinking of the worst case (we divide the array into n parts means k = n, in the subarray formed in worst case, we have only 1 element in each subarray, hence we have to return the largest value among all the splitted subarray, which will be the largest value in the given array).
 * We considered the sum of the array as the end value because thinking of the worst case where k = 1, hence the given array will only be the subarray, in that case we have to find the sum of array in order to find the sum of the split.
 */

public class _410_SplitArrayLargestSum {
    static int splitArray(int[] nums, int k){
        int start = maximumInArray(nums);
        int end = sumOfArray(nums);
        while(start < end){
            int mid = start + (end - start)/2;
            int pieces = findPieces(nums, mid);
            if(pieces <= k){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
    static int findPieces(int[] nums, int mid){
        int sum = 0;
        int pieces = 0;
        int i = 0;
        while(i < nums.length){
            if(sum + nums[i] <= mid){
                sum = sum + nums[i];
                i = i + 1;
            }
            else{
                pieces = pieces + 1;
                sum = 0;
            }
        }
        return pieces + 1;
    }
    static int maximumInArray(int[] nums){
        int max = 0;
        for(int i:nums){
            if(i > max){
                max = i;
            }
        }
        return max;
    }
    static int sumOfArray(int[] nums){
        int sum = 0;
        for(int i: nums){
            sum = sum + i;
        }
        return sum;
    }
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        int k = 5;
        System.out.println(splitArray(nums, k));
    }
}

// Time Complexity: O(n+logn)
// Space Complexity: O(n)