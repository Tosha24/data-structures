// Problem: Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
// For eg: Input: arr = [0,1,0]   ==>   Output: 1

// Approach: Binary Search
/* Solution: 
 * Here we compare the mid value with the mid+1 value.
 * If mid > mid+1, means the peak is on left side of the array
 * If mid < mid+1, means the peak is on its right side
 * At last when start and end crosses each other, we return start as peak will be start after they cross.
 */

public class _852_PeakIndexOfMountainArray {
    static int peakIndex(int[] nums){
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] > nums[mid+1]){
                end = mid - 1;
            }
            else if(nums[mid] < nums[mid+1]) {
                start = mid + 1;
            }
        }
        return start;
    }
    public static void main(String[] args) {
        int[] nums = {0, 10, 5, 2};
        System.out.println(peakIndex(nums));
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(n)