// Problem: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// For eg: Input: nums = [1,3,5,6], target = 4  ==>  Output: 2

// Approach: Binary Search
/* Solution:
 * We search the index position as we search normally using binary search. If the target is not present in the given array, instead of returning -1 we return the value of start as that can only be the possible index where we can insert the given element if it was present. We return start because, after both the pointers (start and end) crosses each other, the start pointer is pointed to the element next to mid (possible index of the element to be inserted).
 */

public class _35_SearchInsertPosition {
    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 6};
        int target = 4;
        System.out.println(searchInsert(nums, target));
    }
    static int searchInsert(int[] nums, int target){
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(target > nums[mid]){
                start = mid + 1;
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                return mid;
            }
        }
        return start;
    }
}

// Time Complexity: O(logn)
// Space Complexity: O(n)