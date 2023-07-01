// Problem: https://leetcode.com/problems/reverse-pairs/

/* Solution (Optimal Solution):
 * 1. We use Count Inversion algorithm along with merge sorting technique to solve this problem.
 * 2. We use merge sort to sort the array and count the number of inversions.
 * 3. We use the countPairs function to count the number of pairs that satisfy the condition.
 * 4. We use the merge function to merge the sorted arrays.
 */

import java.util.*;
public class _493_ReversePairs {
    private static int reversePairs(int[] nums){
        return mergeSort(nums, 0, nums.length - 1);
    }   
    private static int mergeSort(int[] nums, int low, int high){
        int count = 0;
        if(low >= high) return count;
        int mid = (low + high)/2;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(low, mid, high, nums);
        return count;
    }
    private static void merge(int low, int mid, int high, int[] nums){
        ArrayList<Integer> temp = new ArrayList<>();
        int left = low;
        int right = mid + 1;
        int index = 0;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.add(nums[left]);
                left++;
            }else{
                temp.add(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.add(nums[left]);
            left++;
        }
        while(right <= high){
            temp.add(nums[right]);
            right++;
        }
        for(int i = low; i <= high; i++){
            nums[i] = temp.get(i - low);
        }
    }
    private static int countPairs(int[] nums, int low, int mid, int high){
        int count = 0;
        int right = mid + 1;
        for(int i = low; i <= mid; i++){
            while(right <= high && nums[i] > (long) 2 * nums[right]){
                right++;
            }
            count += (right - mid - 1);
        }
        return count;
    }
    public static void main(String[] args){
        int[] nums = {2, 4, 5, 3, 1};
        System.out.println(reversePairs(nums));
    }
}

// Time Complexity: O(nlogn) + O(n) = O(2nlogn)
// Space Complexity: O(n)